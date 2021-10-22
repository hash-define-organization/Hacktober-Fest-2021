#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;
string ConvertBin(long long int num);
long long int ConvertDec(string bin);

void CRC(string dataword, string generator)
{
    int gen_len = generator.length();
    long long int gen = ConvertDec(generator);

    long long int dword = ConvertDec(dataword);
    long long int dividend = dword << (gen_len - 1);
    int shft = (int)ceill(log2l(dividend + 1)) - gen_len;
    long long int rem;
    while ((dividend >= gen) || (shft >= 0))
    {
        rem = (dividend >> shft) ^ gen;
        dividend = (dividend & ((1 << shft) - 1)) | (rem << shft);
        shft = (int)ceill(log2l(dividend + 1)) - gen_len;
    }
    long long int codeword = (dword << (gen_len - 1)) | dividend;
    cout << "\nRemainder: " << ConvertBin(dividend) << endl;
    cout << "\nCodeword : " << ConvertBin(codeword) << endl;
}

int main()
{
    string data, key;
    cout << "Enter the Dataword - \n";
    cin >> data;
    cout << "Enter the Key - \n";
    cin >> key;
    CRC(data, key);
    return 0;
}

string ConvertBin(long long int num)
{
    string bin = "";
    while (num)
    {
        if (num & 1)
            bin = "1" + bin;
        else
            bin = "0" + bin;
        num = num >> 1;
    }
    return bin;
}

long long int ConvertDec(string bin)
{
    long long int num = 0;
    for (int i = 0; i < bin.length(); i++)
    {
        if (bin.at(i) == '1')
            num += 1 << (bin.length() - i - 1);
    }
    return num;
}
