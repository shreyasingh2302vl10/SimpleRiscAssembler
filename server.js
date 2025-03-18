
const express = require("express");
const fileUpload = require("express-fileupload");
const cors = require("cors");
const { exec } = require("child_process");
const path = require("path");
const fs = require("fs");

const app = express();
const PORT = 3000;

app.use(cors());
app.use(fileUpload());

app.post("/upload", (req, res) => {
    if (!req.files || !req.files.assembly) {
        return res.status(400).send("No file uploaded.");
    }

    const inputFile = path.join(__dirname, "input.asm");
    const outputFile = path.join(__dirname, "output.bin");

    // Save the uploaded file as input.asm
    req.files.assembly.mv(inputFile, (err) => {
        if (err) {
            console.error("Error saving file:", err);
            return res.status(500).send("File save error.");
        }

        console.log("File uploaded successfully.");

        // Run the assembler
        const assemblerCommand = `cmd.exe /c assembler.exe input.asm output.bin`;

        // const assemblerCommand = `assembler.exe input.asm output.bin`; // For Windows (if .exe)

        exec(assemblerCommand, (error, stdout, stderr) => {
            if (error) {
                console.error("Assembler execution failed:", stderr || error.message);
                return res.status(500).send("Assembler execution failed.");
            }

            console.log("Assembler executed successfully.");

            // Send output.bin for download
            res.download(outputFile, "output.bin", (err) => {
                if (err) {
                    console.error("File download error:", err);
                    res.status(500).send("Download failed.");
                }
            });
        });
    });
});

app.listen(PORT, () => {
    console.log(`Server running on http://localhost:${PORT}`);
});
