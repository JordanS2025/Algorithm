// Jordan Scott 
// CST-201
// Project 5 : Recursive Strings 
#include <iostream>
#include <fstream>
#include <string>
#include <cstring>
using namespace std;

bool isSlip(string a) // O(n)
{
    int i = 1;
    // check the first character of the string 
    if (a[0] == 'D' || a[0] == 'E') // > the else would return false
    {
        if (a[1]=='F') // check to see if the follwing character is a F 
        {
            //check to see if another F follows or if is a D or E or G
            while ( a[i]=='F')
            {
                i++;
            }
            if (a[i] == 'D' || a[i] == 'E')
            {
                return  isSlip( a.substr(i,a.length()-1));
                
            }
            else if(a[a.length()-1] == 'G')
            {
                
                return true;
            }
            else
            {
                return false;
            }            
            // don't need the else if statement. 
            // need a for loop that check for all the 'F' and then call a substring when its not a F. then 
        }
        else 
        {
            return false;
        }
    }
    else 
    {
         return false;
    }
    // create another if to check to see if more than one "f" follows behind it > if not check to see if it is an D or E 
    // the line above will be insdiee the first if. > 
    // now we need to check to see if it ends with " G"> esle return false. 

}

bool isSlap(string a) // O(n)
{
    // first check to see if the first character is a
    if (a[0]=='A')
    {
         // next we need to check the character count to determine what kind of slap it is 
         if(a.length() == 2)
         {
            // then check to  see if the second/ last character is a H 
            if (a[1]=='H')
            {
                return true;
            }
         }
             //  check to see if a B comes after the A character
         else if (a.length()> 2)// dont think i need else if
         {
             if (a[1]=='B')
             {
                // need to be followed bay a slap or ah 
                // assume we need to check to ah or to have a loop 
                // probaly will have to use the substring to 
                // since the ab it need c at the end to make it a complete slap 
                return isSlap(a.substr(2, a.length()-3));
                return true;
             } 
            else if (a[1]!='B')
             {
                // should be including  after a and before c is when you need to call slip 
                isSlip(a.substr(1, a.length()));
                return true;
             }
             else 
             {
               // cout<< (a.substr(1, a.length()-2))<< endl;
                 return isSlap(a.substr(1, a.length()-2)); 
             }
         
         }
         else
         {
            return false;
         }
         
    }
    else 
    {
        return false;
    }
   

    // then check to see if a slap follows the be then ends with a C 
    // else if a followed by a Slip and ends with a C 
}

bool isSlop(string a) // O(n)
{
    int i = a.length()-1;
    // a slop is a character string that consists of a Slap followed by a  slip 
    // need to find where the slap ends and the slip begins 

    // first check to see if a slap first
    if ( a[0]== 'A')
    {
    if ( a[0]== 'A' && a[1]=='H' && isSlip(a.substr(2,a.length()-1)))
    {
        cout << "Yes" <<endl;
        return true;
    }
    else 
    {
         while ( i < a.length())
        {
            // checks to see if where slap ends
            if( a[i]=='C')
            {
                    if (isSlap (a.substr(0,i+1))&& isSlip(a.substr(i+1,a.length()-1)))
                    {
                        cout << "Yes"<<endl;
                        return true;
                    }
                    else
                    {
                        cout << "No"<< endl;
                        return false;
                    }
            }
            i--;
        }
    }
    }
    else 
    {
        cout<< "No"<<endl;
        return false;
    }      
 
}

int main()
{
   // string nola = "DFGA"; 
    //string nola2 = "AH";
    // AHDFG, ADFGCDFFFFFG, ABAEFGCCDFEFFFFFG < are slops 
    // AHDFGA, DFGAH, ABABCC < are not slops 
    string nola3 = "AHDFGA";
    //isSlip(nola);
   // isSlap(nola2);
    //isSlop (nola3);
    cout << "SLOPS OUTPUT" << endl;
    ifstream file("/Users/bignola/Library/Mobile Documents/com~apple~TextEdit/Documents/Slop.txt"); 
    string nola; 
    int num;
    file >> num;
    for (int i = 0; i < num;i++)
    {
        file >> nola;
        isSlop(nola);
    }
    cout << "END OF OUTPUT";
    return 0;
}

