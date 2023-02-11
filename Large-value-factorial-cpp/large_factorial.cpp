#include <bits/stdc++.h>
using namespace std;

class FactorialClass
{
    private:
        string multiply(string num1, string num2)
        {
            if (num1 == "0" || num2 == "0")
            {
                return "0";
            }
            string temp = num1;
            string result = "";
            string prevResult = "";
            string oldResult = "";
            num1 = num2;
            num2 = temp;
            int carry = 0;
            int dig1 = 0;
            int dig2 = 0;
            int newResult = 0;
            int countDig = 1;
            int num1DigCount = 0;
            for (int i = num1.size() - 1; i >= 0; i--)
            {
                carry = 0;
                dig1 = num1[i] % 48;
                countDig = 1;
                prevResult = "";
                newResult = 0;
                for (int j = num2.size() - 1; j >= 0; j--)
                {
                    dig2 = num2[j] % 48;
                    newResult = (dig1 * dig2) + carry;
                    carry = newResult / 10;
                    newResult = (newResult % 10);
                    prevResult = to_string(newResult) + prevResult;
                    countDig += 1;
                }
                while (countDig - 1 > prevResult.size())
                {
                    prevResult = "0" + prevResult;
                }
                if (carry)
                {
                    prevResult = to_string(carry) + prevResult;
                }

                for (int k = 0; k < num1DigCount; k++)
                {
                    prevResult += "0";
                }
                oldResult = sum2Result(prevResult, oldResult);
                num1DigCount += 1;
            }
            return oldResult;
        }
        string sum2Result(string str1st, string str2nd)
        {
            int carry = 0;
            int str1Size = str1st.size() - 1;
            int str2Size = str2nd.size() - 1;
            int tempResult = 0;
            string sumResult = "";
            if (str1Size < str2Size)
            {
                for (int i = str1Size; i >= 0; i--)
                {
                    tempResult = (str1st[i] % 48) + (str2nd[str2Size] % 48) + carry;
                    sumResult = to_string(tempResult % 10) + sumResult;
                    carry = tempResult / 10;
                    str2Size--;
                }
                for (int i = str2Size; i >= 0; i--)
                {
                    tempResult = (str2nd[i] % 48) + carry;
                    sumResult = to_string(tempResult % 10) + sumResult;
                    carry = tempResult / 10;
                }
            }
            else
            {
                for (int i = str2Size; i >= 0; i--)
                {
                    tempResult = (str1st[str1Size] % 48) + (str2nd[i] % 48) + carry;
                    sumResult = to_string(tempResult % 10) + sumResult;
                    carry = tempResult / 10;
                    str1Size--;
                }
                for (int i = str1Size; i >= 0; i--)
                {
                    tempResult = (str1st[i] % 48) + carry;
                    sumResult = to_string(tempResult % 10) + sumResult;
                    carry = tempResult / 10;
                }
            }
            if (carry > 0)
            {
                sumResult = to_string(carry) + sumResult;
            }

            return sumResult;
        }

    public:
        string factorial(int givenValue)
        {
            if (givenValue < 0)
            {
                return "Math Error";
            }
            string outputResult = "1";
            for (int i = 2; i <= givenValue; i++)
            {
                outputResult = multiply(outputResult, to_string(i));
            }
            return outputResult;
        }
        void outputGenerate(int givenInput, string outputResult){
            cout<<"The factorial of "<<givenInput<<" : "<<outputResult;
        }
};

// Main Method
int main()
{
    FactorialClass factorialClassInstance;
    int inputValue;
    cin >> inputValue;
    string factorialValue = factorialClassInstance.factorial(inputValue);
    factorialClassInstance.outputGenerate(inputValue,factorialValue);
    return 0;
}