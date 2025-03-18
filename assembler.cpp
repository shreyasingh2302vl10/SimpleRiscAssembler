#include <bits/stdc++.h>
#include <windows.h>
using namespace std;
void first(vector<string> &v, vector<string> &current)
{
    for (int i = 1; i < v.size(); i++)
    {
        // Check if it is like R0, R1, #25 etc.
        if (v[i][0] == 'R')
        { // Register like R0, R1

            int a = stoi(v[i].substr(1));              // Convert R0 to 0
            string present = bitset<4>(a).to_string(); // Register only needs 5 bits
            current.push_back(present);
        }
        else
        {
            // if(v[i][j][0] == '#') v[i][j] = v[i][j].substr(1); // Remove '#' if present
            current.push_back("01");
            int a = stoi(v[i]);
            string present = bitset<16>(a).to_string();
            current.push_back(present);
        }
    }
    if (current.size() == 5)
    {
        current.push_back("00000000000000");
    }
    // cout<<"first time:";
    // for(auto it:current) cout<<it<<" ";
    // cout<<endl;
}
void h(vector<string> &v, vector<string> &current)
{
    for (int i = 0; i < 26; i++)
    {
        current.push_back("0");
    }
}
void cmp(vector<string> &v, vector<string> &current)
{
    current.push_back("0000");
    for (int i = 1; i < v.size(); i++)
    {
        // Check if it is like R0, R1, #25 etc.
        if (v[i][0] == 'R')
        { // Register like R0, R1

            int a = stoi(v[i].substr(1));              // Convert R0 to 0
            string present = bitset<4>(a).to_string(); // Register only needs 5 bits
            current.push_back(present);
        }
        else
        {
            // if(v[i][j][0] == '#') v[i][j] = v[i][j].substr(1); // Remove '#' if present
            current.push_back("01");
            int a = stoi(v[i]);
            string present = bitset<16>(a).to_string();
            current.push_back(present);
        }
    }
    if (current.size() == 5)
    {
        current.push_back("00000000000000");
    }
}
void Not(vector<string> &v, vector<string> &current)
{
    // current.push_back("0000");
    for (int i = 1; i < v.size(); i++)
    {
        // Check if it is like R0, R1, #25 etc.
        if (i == 2)
        {
            current.push_back("0000");
            // continue;
        }
        if (v[i][0] == 'R')
        { // Register like R0, R1

            int a = stoi(v[i].substr(1));              // Convert R0 to 0
            string present = bitset<4>(a).to_string(); // Register only needs 5 bits
            current.push_back(present);
        }
        else
        {
            // if(v[i][j][0] == '#') v[i][j] = v[i][j].substr(1); // Remove '#' if present
            current.push_back("01");
            int a = stoi(v[i]);
            string present = bitset<16>(a).to_string();
            current.push_back(present);
        }
    }
    if (current.size() == 5)
    {
        current.push_back("00000000000000");
    }
}
void ld(vector<string> &v, vector<string> &current)
{
    current.push_back("0000");
    for (int i = 1; i < v.size(); i++)
    {
        // Check if it is like R0, R1, #25 etc.
        if (v[i][0] == 'R')
        { // Register like R0, R1

            int a = stoi(v[i].substr(1));              // Convert R0 to 0
            string present = bitset<4>(a).to_string(); // Register only needs 5 bits
            current.push_back(present);
        }
        else
        {
            // if(v[i][j][0] == '#') v[i][j] = v[i][j].substr(1); // Remove '#' if present
            current.push_back("01");
            current.push_back("0000");
            for (int j = 0; j < v[i].size(); j++)
            {
                if (v[i][j] == '0')
                    current.push_back("0000");
                else if (v[i][j] == '1')
                    current.push_back("0001");
                else if (v[i][j] == '2')
                    current.push_back("0010");
                else if (v[i][j] == '3')
                    current.push_back("0011");
                else if (v[i][j] == '4')
                    current.push_back("0100");
                else if (v[i][j] == '5')
                    current.push_back("0101");
                else if (v[i][j] == '6')
                    current.push_back("0110");
                else if (v[i][j] == '7')
                    current.push_back("0111");
                else if (v[i][j] == '8')
                    current.push_back("1000");
                else if (v[i][j] == '9')
                    current.push_back("1001");
                else if (v[i][j] == 'A')
                    current.push_back("1010");
                else if (v[i][j] == 'B')
                    current.push_back("1011");
                else if (v[i][j] == 'C')
                    current.push_back("1100");
                else if (v[i][j] == 'D')
                    current.push_back("1101");
                else if (v[i][j] == 'E')
                    current.push_back("1110");
                else if (v[i][j] == 'F')
                    current.push_back("1111");
            }
        }
    }
    // current.push_back("0000");
    // if(current.size()==5){
    //     current.push_back("00000000000000");
    // }
}
void b(vector<string> &v, vector<string> &current, map<string, int> &labelMap, int i)
{
    // bitset<16> binary(labelMap[v[1]]);
    // current.push_back("0000000000");
    // current.push_back(binary.to_string());
    string operand = v[1]; // Operand can be a label or direct address
    string binaryValue;

    if (labelMap.find(operand) != labelMap.end())
    {
        //  If operand is a label, convert label value to 16-bit binary
        binaryValue = bitset<32>((labelMap[operand] - i * 4)).to_string();
        current.push_back(binaryValue.substr(5));
        return;
    }
    else
    {
        //  Operand is a direct address (hex or decimal), convert manually
        for (char ch : operand)
        {
            if (ch == '0')
                binaryValue += "0000";
            else if (ch == '1')
                binaryValue += "0001";
            else if (ch == '2')
                binaryValue += "0010";
            else if (ch == '3')
                binaryValue += "0011";
            else if (ch == '4')
                binaryValue += "0100";
            else if (ch == '5')
                binaryValue += "0101";
            else if (ch == '6')
                binaryValue += "0110";
            else if (ch == '7')
                binaryValue += "0111";
            else if (ch == '8')
                binaryValue += "1000";
            else if (ch == '9')
                binaryValue += "1001";
            else if (ch == 'A' || ch == 'a')
                binaryValue += "1010";
            else if (ch == 'B' || ch == 'b')
                binaryValue += "1011";
            else if (ch == 'C' || ch == 'c')
                binaryValue += "1100";
            else if (ch == 'D' || ch == 'd')
                binaryValue += "1101";
            else if (ch == 'E' || ch == 'e')
                binaryValue += "1110";
            else if (ch == 'F' || ch == 'f')
                binaryValue += "1111";
            else
            {
                cout << "Error: Invalid character in address: " << ch << endl;
                return;
            }
        }
    }

    current.push_back("0000000000"); // Placeholder instruction
    current.push_back(binaryValue);  // Store binary value
}
// -------------------------------------------------main function-------------------------------------------------
int main()
{
    //     vector<vector<string>> v;
    //     ifstream file("input.asm"); // Open the file

    //     if (!file) {
    //         cout << "File not found!" << endl;
    //         return 0;
    //     }

    //     string line;
    //     // Read the file line by line
    //    // Read the file line by line
    // while(getline(file, line)) {
    //     // Remove comments (anything after "//")
    //     size_t pos = line.find("//");
    //     if (pos != string::npos) {
    //         line = line.substr(0, pos);
    //     }

    //     // Remove leading and trailing whitespace
    //     line.erase(0, line.find_first_not_of(" \t"));
    //     line.erase(line.find_last_not_of(" \t") + 1);

    //     // Skip empty lines
    //     if (line.empty()) {
    //         continue;
    //     }

    //     vector<string> temp;
    //     string word = "";

    //     // Traverse the line character by character
    //     for(char ch:line){
    //         if(ch == ' ' || ch == ','){
    //             if(!word.empty()){
    //                 temp.push_back(word); // Store word (excluding comma)
    //                 word = "";
    //             }
    //         }
    //         else{
    //             word += ch;
    //         }
    //     }
    //     if(!word.empty()) temp.push_back(word);

    //     v.push_back(temp);
    // }
    vector<vector<string>> v;
    map<string, int> labelMap;  // Stores labels and their corresponding line numbers
    ifstream file("input.asm"); // Open the file

    if (!file)
    {
        cout << "File not found!" << endl;
        return 0;
    }

    string line;
    int lineCounter = 0;

    while (getline(file, line))
    {
        // Remove comments (anything after "//")
        size_t pos = line.find("//");
        if (pos != string::npos)
        {
            line = line.substr(0, pos);
        }

        // Remove leading and trailing whitespace
        line.erase(0, line.find_first_not_of(" \t"));
        line.erase(line.find_last_not_of(" \t") + 1);

        // Skip empty lines
        if (line.empty())
        {
            continue;
        }

        vector<string> temp;
        string word = "";
        bool labelFound = false;

        // Check if the line starts with a label (ends with ':')
        size_t colonPos = line.find(':');
        if (colonPos != string::npos)
        {
            string label = line.substr(0, colonPos);
            label.erase(label.find_last_not_of(" \t") + 1); // Remove trailing spaces
            labelMap[label] = lineCounter;                  // Store label with line number
            line = line.substr(colonPos + 1);               // Remove the label part
            line.erase(0, line.find_first_not_of(" \t"));   // Trim spaces after the label
            labelFound = true;
        }

        // Traverse the line character by character
        for (char ch : line)
        {
            if (ch == ' ' || ch == ',')
            {
                if (!word.empty())
                {
                    temp.push_back(word); // Store word (excluding comma)
                    word = "";
                }
            }
            else
            {
                word += ch;
            }
        }
        if (!word.empty())
            temp.push_back(word);

        if (!temp.empty())
        {
            v.push_back(temp);
            lineCounter += 4; // Increase the instruction counter only for valid lines
        }
    }

    file.close();
    // cout << "\nLabels:\n";
    //     for (const auto &entry : labelMap) {
    //         cout << entry.first << " -> " << entry.second << endl;
    //     }
    // cout<<"the end\n"<<endl;

    unordered_map<string, string> OPCODES = {
        {"ADD", "00000"}, {"SUB", "00001"}, {"MUL", "00010"}, {"DIV", "00011"}, {"MOD", "00100"}, {"CMP", "00101"}, {"AND", "00110"}, {"OR", "00111"}, {"NOT", "01000"}, {"MOV", "01001"}, {"LSL", "01010"}, {"LSR", "01011"}, {"ASR", "01100"}, {"NOP", "01101"}, {"LD", "01110"}, {"ST", "01111"}, {"BEQ", "10000"}, {"BGT", "10001"}, {"B", "10010"}, {"CALL", "10011"}, {"RET", "10100"}, {"HLT", "11111"}};
    unordered_map<string, int> check = {
        {"ADD", 4}, {"SUB", 4}, {"MUL", 4}, {"DIV", 4}, {"MOD", 4}, {"CMP", 3}, {"AND", 4}, {"OR", 4}, {"NOT", 3}, {"MOV", 3}, {"LSL", 4}, {"LSR", 4}, {"ASR", 4}, {"NOP", 1}, {"LD", 4}, {"ST", 3}, {"BEQ", 2}, {"BGT", 2}, {"B", 2}, {"CALL", 2}, {"RET", 1}, {"HLT", 1}};
    vector<vector<string>> ans;
    // Process each line
    for (int i = 0; i < v.size(); i++)
    {
        vector<string> current;
        if (check[v[i][0]] != v[i].size())
        {
            // cout<<v[i][0]<<" "<<v[i].size()<<endl;
            // cout<<"INVALID STATEMET\n";
            ans.push_back({"INVALID STATEMENT"});
            continue;
        }

        current.push_back(OPCODES[v[i][0]]); // Push the opcode binary
        // cout<<v[i][0]<<endl;
        // Check if the last argument is an immediate value or a register
        if (v[i][0] == "BGT" || v[i][0] == "B" || v[i][0] == "CALL" || v[i][0] == "BEQ")
        {
            ans.push_back(current);
            continue;
        }
        if (!(isdigit(v[i][v[i].size() - 1][0])))
            current.push_back("0"); // It's a register
        else
            current.push_back("1"); // It's an immediate value

        ans.push_back(current);
    }
    // cout<<"this is v"<<endl;

    // for(auto it:v){
    //     for(auto itt:it) cout<<itt<<" ";
    //     cout<<endl;
    // }
    // cout<<"v end"<<endl;
    for (int i = 0; i < v.size(); i++)
    {
        // cout<<i<<endl;
        if (ans[i][0] == "INVALID STATEMENT")
        {
            // cout<<v[i][0]<<" "<<v[i].size()<<endl;
            // cout<<"INVALID STATEMET\n";
            continue;
        }
        if (v[i][0] == "ADD" || v[i][0] == "SUB" || v[i][0] == "MUL" || v[i][0] == "DIV" || v[i][0] == "MOD" || v[i][0] == "AND" || v[i][0] == "OR" || v[i][0] == "LSL" || v[i][0] == "LSR" || v[i][0] == "ASR")
        {
            first(v[i], ans[i]);
            // continue;
        }
        else if (v[i][0] == "CMP")
            cmp(v[i], ans[i]);
        else if (v[i][0] == "NOT" || v[i][0] == "MOV")
            Not(v[i], ans[i]);
        else if (v[i][0] == "LD" || v[i][0] == "ST")
        {
            ld(v[i], ans[i]);
        }
        else if (v[i][0] == "NOP" || v[i][0] == "HLT" || v[i][0] == "RET")
            h(v[i], ans[i]);
        else if (v[i][0] == "CALL" || v[i][0] == "B" || v[i][0] == "BGT" || v[i][0] == "BEQ")
            b(v[i], ans[i], labelMap, i);
    }

    // cout<<"this the call i am making ";
    // vector<string> gh={"11111"};
    // first(v[0],gh);
    // for(auto it:gh) cout<<it;
    // cout<<"now done"<<endl;
    // Output the result
    // for(auto it:ans){
    // //    cout<<it.size()<<"  "<<endl;
    //     for(auto itt:it) cout<<itt;
    //     cout<<endl;
    // }
    ofstream outFile("output.bin", ios::binary); // Open file in binary mode

    if (!outFile)
    {
        cerr << "Error: Could not open output.bin for writing!" << endl;
        return 1; // Exit if file can't be opened
    }

    for (auto &it : ans)
    {
        for (auto &itt : it)
        {
            outFile.write(itt.c_str(), itt.size()); // Write string as binary
        }
        outFile.put('\n'); // Separate entries with newline
    }
    outFile.close();
    return 0;
}