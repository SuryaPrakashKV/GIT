#include<iostream>
#include<string>
using namespace std;
int main()
{
    cout<<" URL Shortener System"<<endl;
    cout<<"1. Shorten URL "<<endl;
    cout<<"2. Create Custom Alias "<<endl;
    cout<<"3. Expand URL "<<endl;
    cout<<"4. List All Mappings "<<endl;
    cout<<"5. Delete Mapping "<<endl;
    cout<<"6. Exit "<<endl;
    cout<<"Enter your choice: ";
    int n;
    string *store = new string[1000];
    string *shortcodes = new string[1000];
    int sc=1;
    string a ="short";
    int ind=0;
    while(1)
    {
        int valid=1;
        cin>>n;
        if(n<=0)
        {
            cout<<"Invalid choice! Try again."<<endl;
            valid=0;
        }
        if(valid)
        {
            switch(n)
            {
                case 1:
                {
                    string url;
                    getline(cin,url);
                    getline(cin,url);
                    cout<<"Shortened URL: short"<<sc<<" -> ";
                    cout<<url<<" "<<endl;
                    string shortcode = a + to_string(sc);
                    shortcodes[ind]= shortcode;
                    store[ind]=url;
                    ind++;
                    sc++;
                    break;
                }
                case 2:
                {
                    string new_url;
                    string new_code;
                    getline(cin,new_url);
                    getline(cin,new_url);
                    cout<<"Enter Custom Alias: ";
                    getline(cin,new_code);
                    int f=0;
                    for(int i=0;i<ind;i++)
                    {
                        if(new_code==shortcodes[i])
                        {
                            f=1;
                            cout<<"Error: Alias already exists!"<<endl;
                            break;
                        }
                    }
                    if(!f)
                    {
                        cout<<"Alias Created: "<<new_code<<" -> "<<new_url<<endl;
                        shortcodes[ind]=new_code;
                        store[ind]=new_url;
                        ind++;
                    }
                    break;
                }
                case 3:
                {
                    
                    string search;
                    cin.ignore();
                    getline(cin,search);
                    int f=0;
                    for(int i=0;i<ind;i++)
                    {
                        if(shortcodes[i]==search)
                        {
                            cout<<"Expanded URL: "<<store[i]<<endl;
                            f=1;
                            break;
                        }
                    }
                    if(!f)
                    {
                        cout<<"Error : Short code not found!"<<endl;
                        break;
                        break;
                    }
                    break;
                }
                case 4:
                {
                    cout<<endl;
                    int k=0;
                    if(ind==0)
                    {
                        cout<<"No Mappings found."<<endl;
                        k=1;
                    }
                    if(!k)
                    {

                        cout<<"Short Code  Long URL "<<endl;
                        for(int i=0;i<ind;i++)
                        {
                            if(shortcodes[i][0]=='s')
                            {
                                cout<<shortcodes[i]<<"      "<<store[i]<<" "<<endl;
                            }
                        }
                        for(int i=0;i<ind;i++)
                        {
                            if(shortcodes[i][0]!='s')
                            {
                                cout<<shortcodes[i]<<"        "<<store[i]<<endl;
                            }
                        }
                    }
                    break;
                }
                case 5:
                {
                    string code;
                    cin>>code;
                    int k=0;
                    for(int i=0;i<ind;i++)
                    {
                        if(code==shortcodes[i])
                        {
                            k=1;
                            for(int j=i;j<ind-1;j++)
                            {
                                shortcodes[j]=shortcodes[j+1];
                                store[j]=store[j+1];
                            }
                        }
                    }
                    if(!k)
                    {
                        cout<<"Error: Short code not found!"<<endl;
                    }
                    if(k)
                    {
                        cout<<"Mapping deleted Successfully."<<endl;
                        ind--;
                    }
                    break;
                }
                case 6:
                cout<<"Exiting System. Goodbye!";
                return 0;
                break;
                default:
                cout<<"Invalid choice! "<<endl;
            }
        }   
    }
}