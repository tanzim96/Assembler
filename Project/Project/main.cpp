#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;
string setRs(string rs);
string setRsValue(string rs);
string setRd(string rd);
string setRdValue(string rd);
void storeRegValue(string reg,string val);
int binaryToDecimal(int n);
int decimalToBinary(int n);
string fivebit(string b);
string opc, insName, rs, rd, done,Imm,Result, user_input;
string R[2][16];
string registers[3][32];



int main()
{
    /*
    Here in the 2D array, 3 different information are stored.
    1. The name of the instruction
    2. The corresponding opc
    */
    R[0][0] = "AND";
    R[1][0] = "0000";
    R[0][1] = "OR";
    R[1][1] = "0001";
    R[0][2] = "NOR";
    R[1][2] = "0010";
    R[0][3] = "ADD";
    R[1][3] = "0100";
    R[0][4] = "SUB";
    R[1][4] = "0101";
    R[0][5] = "LW";
    R[1][5] = "0111";
    R[0][6] = "SW";
    R[1][6] = "1000";
    R[0][7] = "Din";
    R[1][7] = "1001";
    R[0][8] = "Dout";
    R[1][8] = "1010";
    R[0][9] = "Slt";
    R[1][9] = "1011";
    R[0][10]="Sll";
    R[1][10]="0011";
    R[0][11]="ADDi";
    R[1][11]="0110";
    R[0][12]="Slti";
    R[1][12]="1100";
    R[0][13]="Beq";
    R[1][13]="1101";
    R[0][14]="Bne";
    R[1][14]="1110";
    R[0][15]="Jump";
    R[1][15]="1111";


    //Included registers are $t0 - $t9
    //And registers $s0 - $s9
    //Again here the first row of the 2D array contains the names of the registers
    //The second row contains the corresponding BINARY values


    registers[0][0] = "$zero";   //NAME OF THE REGISTER
    registers[1][0] = "00000"; //BINARY VALUE OF THE REGISTER
    registers[0][1] = "$sp";
    registers[1][1] = "00001";
    registers[0][2] = "$v0";
    registers[1][2] = "00010";
    registers[0][3] = "$v1";
    registers[1][3] = "00011";
    registers[0][4] = "$a0";
    registers[1][4] = "00100";
    registers[0][5] = "$a1";
    registers[1][5] = "00101";
    registers[0][6] = "$a2";
    registers[1][6] = "00110";
    registers[0][7] = "$a3";
    registers[1][7] = "00111";
    registers[0][8] = "$s0";
    registers[1][8] = "01000";
    registers[0][9] = "$s1";
    registers[1][9] = "01001";
    registers[0][10] = "$s2";
    registers[1][10] = "01010";
    registers[0][11] = "$s3";
    registers[1][11] = "01011";
    registers[0][12] = "$s4";
    registers[1][12] = "01100";
    registers[0][13] = "$s5";
    registers[1][13] = "01101";
    registers[0][14] = "$s6";
    registers[1][14] = "01110";
    registers[0][15] = "$s7";
    registers[1][15] = "01111";
    registers[0][16] = "$s8";
    registers[1][16] = "10000";
    registers[0][17] = "$s9";
    registers[1][17] = "10001";
    registers[0][18] = "$t0";
    registers[1][18] = "10010";
    registers[0][19] = "$t1";
    registers[1][19] = "10011";
    registers[0][20] = "$t2";
    registers[1][20] = "10100";
    registers[0][21] = "$t3";
    registers[1][21] = "10101";
    registers[0][22] = "$t4";
    registers[1][22] = "10110";
    registers[0][23] = "$t5";
    registers[1][23] = "10111";
    registers[0][24] = "$t6";
    registers[1][24] = "11000";
    registers[0][25] = "$t7";
    registers[1][25] = "11001";
    registers[0][26] = "$t8";
    registers[1][26] = "11010";
    registers[0][27] = "$t9";
    registers[1][27] = "11011";
    registers[0][28] = "$at";
    registers[1][28] = "11100";
    registers[0][29] = "$k0";
    registers[1][29] = "11101";
    registers[0][30] = "$k1";
    registers[1][30] = "11110";
    registers[0][31] = "$fp";
    registers[1][31] = "11111";

for(int i=0;i<32;i++)
    {
        registers[2][i]="0";
    }

    ifstream input_file("Input.txt");
while(getline(input_file,user_input))
{


    insName = "";
    for(int i=0; user_input[i] != ' '; i++){
        insName += user_input[i];

    }

	bool found;

	for(int i=0; i<16; i++)
    {
        if(insName == R[0][i])
        {
            found = true;
            opc = R[1][i];
            break;
        }
    }

	if(found==false)
        cout<<"Incorrect instruction"<<endl;

	else{

		// AND Operation
		if(opc=="0000"){
                string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;

			string rsValue =setRsValue(rs);
			string rdValue =setRdValue(rd);

            int a = stoi(rsValue);
			int b = stoi(rdValue);
			int result = decimalToBinary(a&b);
			stringstream ss;
			ss << result;
			ss >> rsValue;
			rs= setRs(rs);
			rd = setRd(rd);



		}
		// OR Operation
		else if(opc=="0001"){
            string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;

			string rsValue =setRsValue(rs);
			string rdValue =setRdValue(rd);

            int a = stoi(rsValue);
			int b = stoi(rdValue);
			int result = decimalToBinary(a|b);
			stringstream ss;
			ss << result;
			ss >> rsValue;
			rs= setRs(rs);
			rd= setRd(rd);


		}
		// NOR Operation
		else if(opc=="0010"){
           string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;

			string rsValue =setRsValue(rs);
			string rdValue =setRdValue(rd);

            int a = stoi(rsValue);
			int b = stoi(rdValue);
			int result = decimalToBinary(!(a|b));
			stringstream ss;
			ss << result;
			ss >> rsValue;
			rs= setRs(rs);
			rd = setRd(rd);

		}
		// ADD Operation
		else if(opc=="0100"){
              string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;

			string rsValue =setRsValue(rs);
			string rdValue =setRdValue(rd);

            int a = stoi(rsValue);
			int b = stoi(rdValue);
			int result = decimalToBinary(a+b);
			stringstream ss;
			ss << result;
			ss >> rsValue;
			rs= setRs(rs);
			rd = setRd(rd);



		}
		// SUB Operation
		else if(opc=="0101"){
                string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;

			string rsValue =setRsValue(rs);
			string rdValue =setRdValue(rd);

            int a = stoi(rsValue);
			int b = stoi(rdValue);
			int result = decimalToBinary(a-b);
			stringstream ss;
			ss << result;
			ss >> rsValue;
			rs= setRs(rs);
			rd = setRd(rd);



		}
		// LW Operation
		else if(opc=="0111"){
            string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;
            string temprs=rs;
            string temprd=rd;
			storeRegValue(rs,setRsValue(rd));
			rs=setRs(temprs);
			rd=setRs(temprd);

		}
		// SW Operation
		else if(opc=="1000"){

            string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;
            string temprs=rs;
            string temprd=rd;
			storeRegValue(rd,setRsValue(rs));
			rs=setRs(temprs);
			rd=setRs(temprd);


		}
		// Din Operation
		else if(opc=="1001"){
            string temprs;
                int space=0;
        string word;
            for(auto x : user_input){
            if(x == ' ' && space==1){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                    space++;
                }
                else{
                    word += x;
                }
            }
            rs=word;
            temprs=rs;
			rs = setRsValue(rs);
			rs = setRs(temprs);
        }


		// Dout Operation
		else if(opc=="1010"){
            string temprs=rs;
                int space=0;
        string word;
            for(auto x : user_input){
            if(x == ' ' && space==1){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                    space++;
                }
                else{
                    word += x;
                }
            }
            rs=word;
            temprs=rs;
			rs = setRsValue(rs);
			rs = setRs(temprs);
            }

		// Slt Operation
		else if(opc=="1011"){

            string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               rd = word;
            string temprs,temprd;
            temprs=rs;
            temprd=rd;
			rs = setRsValue(rs);
			rd = setRdValue(rd);

            int res=rd.compare(rs);

			if(res>0){
				storeRegValue(temprs,"1");
			}
			else{
				storeRegValue(temprs,"0");
			}

			rs=setRs(temprs);
			rd=setRs(temprd);

		}
		//Sll
		else if(opc=="0011")
		{
			int space=0;
            string word;
            for(auto x : user_input){
            if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                    space++;
                }
                else{
                    word += x;
                }
            }
            Imm=word;
            int current=stoi(setRsValue(rs));
            current=current*pow(2,stoi(word));
            stringstream ss;
            string valueString;
            ss<<current;
            ss>>valueString;
            storeRegValue(rs,valueString);
            rs=setRs(rs);



		}


		//ADDi
		else if(opc=="0110")
		{
		    int space;
            string word;
            for(auto x : user_input){
            if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                    space++;
                }
                else{
                    word += x;
                }
            }
            string temprs=rs;
            rs=setRsValue(rs);
                Imm=word;
            int a = stoi(rs);
			int b = stoi(Imm);
			int result = a+b;
			stringstream ss;
			ss << result;
			ss >> rs;
			storeRegValue(temprs,rs);
                rs=setRs(temprs);


		}
		//Slti
		else if(opc=="1100")
		{
				string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               Imm = word;
            string temprs,temprd;
            temprs=rs;
            temprd=Imm;
			rs = setRsValue(rs);

            int res=Imm.compare(rs);

			if(res>0){
				storeRegValue(temprs,"1");
			}
			else{
				storeRegValue(temprs,"0");
			}

			rs=setRs(temprs);

		}
		//Beq
		else if(opc=="1101")
		{
			string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               Imm = word;
            string temprs;
            temprs=rs;
			rs = setRsValue(rs);

            int res=rd.compare(rs);

			if(res==0){
				storeRegValue(temprs,"1");
			}
			else{
				storeRegValue(temprs,"0");
			}

			rs=setRs(temprs);

		}

		//Bne
		else if(opc=="1110")
		{
            string word;

             for(auto x : user_input){
                if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                }
                else{
                    word += x;
                }
               }
               Imm = word;
            string temprs;
            temprs=rs;
			rs = setRsValue(rs);

            int res=rd.compare(rs);
			if(res!=0){
				storeRegValue(temprs,"1");
			}
			else{
				storeRegValue(temprs,"0");
			}

			rs=setRs(temprs);
			}
    if(opc=="1111")
    {
        int space;
     string word;
            for(auto x : user_input){
            if(x == ','){
                     rs = word;
                    word = "";
                }
                else if(x == ' '){
                    word = "";
                    space++;
                }
                else{
                    word += x;
                }
            }
            Imm=word;
    }
		rs = fivebit(rs);
		rd = fivebit(rd);
        if(opc=="1101" || opc=="0011" || opc=="0110" || opc=="1100" || opc=="1110")
        {
            int ImmNumber=decimalToBinary(stoi(Imm));
            stringstream ss;
            ss<<ImmNumber;
            ss>>Imm;
            Imm=fivebit(Imm);
            cout<< opc << " " << rs << " "<< Imm<<endl;
        }

        else if(opc=="1001" || opc =="1010")
        {
            cout<< opc << " " << rs << endl;
        }
        else if(opc=="1111")
        {
            int ImmNumber=decimalToBinary(stoi(Imm));
            stringstream ss;
            if(stoi(Imm)>1023)
            {
                cout<<"The value is greater than the max";
                exit(0);
            }
            ss<<ImmNumber;
            ss>>Imm;
        int counter = 10 - Imm.size();
        for(int i=0;i<counter;i++)
        {
            Imm="0"+Imm;
        }

        cout<<opc<<" "<<Imm<<endl;
        }
        else
        cout<< opc << " " << rs  <<  " " << rd << endl;

	}
}
input_file.close();

}

string fivebit(string b){
    string result;
    int count = 5 - b.size();

    if(b.size() <5){
        switch(count) {
          case 1:
            result = "0"+ b;
            break;
          case 2:
            result = "00"+ b;
            break;
          case 3:
            result = "000"+ b;
            break;
          case 4:
            result = "0000"+ b;
            break;
          case 5:
            result = "00000"+ b;
            break;
          default:
            result = b;
        }

    }else{
        result = b;
    }
    return result;
}


int binaryToDecimal(int n)
{
    int num = n;
    int dec_value = 0;

    // Initializing base value to 1, i.e 2^0
    int base = 1;

    int temp = num;
    while (temp) {
        int last_digit = temp % 10;
        temp = temp / 10;

        dec_value += last_digit * base;

        base = base * 2;
    }

    return dec_value;
}


int decimalToBinary(int n)
{
    int r;
    int bn = 0, i = 1;

    while(n != 0) {
        r = n%2;
        n = n/2;
        bn= bn + (r*i);
        i = i*10;
    }
    return bn;
}

string setRs(string rs){
    bool found;
	for(int i=0; i<32; i++)
        {
			if(rs == registers[0][i]){
                    found =true;
				rs = registers[1][i];
			}
		}
		if(found==false)
        {
            cout<<"Register not found";
            exit(0);
        }
	return rs;
}
string setRsValue(string rs){
	for(int i=0; i<32; i++)
        {
			if(rs == registers[0][i]){
				rs = registers[2][i];
				break;
			}
		}
	return rs;
}
void storeRegValue(string reg,string val){
	for(int i=0; i<32; i++)
        {
			if(reg == registers[0][i]){
                registers[2][i]=val;
                break;
			}
		}
}
string setRd(string rd){
    bool found;
	for(int i=0; i<32; i++)
        {

			if(rd == registers[0][i]){
                    found=true;
				rd = registers[1][i];
			}
		}
		if(found==false)
        {
            cout<<"Register not found";
            exit(0);
        }
	return rd;
}
string setRdValue(string rd){
	for(int i=0; i<32; i++)
        {
			if(rd == registers[0][i]){
				rd = registers[2][i];
			}
		}
	return rd;
}
