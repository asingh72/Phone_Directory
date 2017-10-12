#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <vector>

using namespace std;
int PARTITION(vector<string>&,int ,int );
void R_QUICKSORT(vector<string>&,int ,int );
int R_PARTITION(vector<string>&,int,int );
int binarySearch(vector<string>&,string,int,int);
void delete_contact(vector<string>&,string,string);
void display(vector<string>&);
void insert(string,string,string);
vector<string> a;





int binarySearch(vector<string>&a, string value, int left, int right) {
    while (left <= right) {
        int middle = (left + right) / 2;
        string delimiter=",";
        
        string token=a[middle].substr(0,a[middle].find(delimiter));
        
        
        if (token== value)
            return middle;
        else if (token> value)
        {
            right = middle - 1;
            
        }
        else
        {
            left = middle + 1;
        }
    }
    return -1;
}

void delete_contact(vector<string>&a,string search,string filename)
{
    
    int nw=binarySearch(a,search,0,(int)a.size()-1);
    if(nw==-1)
    {
        cout<<"Name not Found"<<endl;
    }
    else
    {
        
        a.erase((a.begin()+nw));
        display(a);
    }
    
}

vector<string> read(string filename)
{
    a.clear();
    string line;
    fstream file_(filename.c_str());
    if(file_.is_open())
    {
        while (getline(file_,line))
        {
            a.push_back(line);
        }
    }
    else{
        cout<< "file is not open "<<endl;
    }
    file_.close();
    return a;
    
}


int main(int argc, char *argv[])
{
    string filename=argv[1];
    vector<string>a=read(filename);
    vector<string>b;
    int choice=1;
    int n,p,r,num;
    char name[100];
    string contact,name_s;
    
    
    
    
    char phone[100];
    
    while(choice<5&&choice>0)
    {
        cout<<"1) sort_contact"<<endl<<"2) search"<<endl<<"3) delete"<<endl<<"4) insert"<<endl<<"5) exit"<<endl;
        cout<<"Enter the choice"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 1:
                n=(int)a.size();
                p=0;
                r=n-1;
                R_QUICKSORT(a,p,r);
                display(a);
                break;
                
            case 2:
                
                cout<<"Enter the name"<<endl;
                
                cin.ignore();
                cin.getline(name,sizeof(name));
                
                
                num=binarySearch(a, name, 0, (int)a.size()-1);
                if(num==-1)
                    cout<<"name not Found"<<endl;
                else
                    cout<<a[num]<<endl;
                break;
            case 3:
                
                cout<<"Enter the name"<<endl;
                
                cin.ignore();
                cin.getline(name,sizeof(name));
                
                
                delete_contact(a, name, filename);
                
                
                break;
                
            case 4:
                cout<<"Enter the name"<<endl;
                
                cin.ignore();
                cin.getline(name,sizeof(name));
                cout<<"Enter the phone"<<endl;
                
                cin.ignore();
                cin.getline(phone,sizeof(name));
                
                contact=string(name)+", "+phone;
                a.push_back(contact);
                
                n=(int)a.size();
                p=0;
                r=n-1;
                R_QUICKSORT(a,p,r);
                
                display(a);
                
                
                
            case 5:break;
                
                
        }
    }
    
    return 0;
}
void display(vector<string>&a)
{
    for(int i=0;i<a.size();i++)
        cout<<a[i]<<endl;
}

void insert(string name,string phone_number,string filename)
{
    
    ofstream myfile;
    myfile.open(filename.c_str(),ios_base::app);
    string contact=name+","+phone_number;
    
    myfile<<contact;
    
    
}

void R_QUICKSORT(vector<string>&a,int p,int r)
{
    int q;
    if(p<r)
    {
        q=R_PARTITION(a,p,r);
        R_QUICKSORT(a,p,q-1);
        R_QUICKSORT(a,q+1,r);
    }
}

int R_PARTITION(vector<string> &a,int p,int r)
{
    int i=p+rand()%(r-p+1);
    string temp;
    temp=a[r];
    a[r]=a[i];
    a[i]=temp;
    return PARTITION(a,p,r);
}

int PARTITION(vector<string>&a,int p,int r)
{
    string temp,temp1;
    string x=a[r];
    
    int i=p-1;
    for(int j=p;j<r;j++)
    {
        
        if(a[j]<=x)
        {
            
            i=i+1;
            temp=a[i];
            a[i]=a[j];
            a[j]=temp;
        }
    }
    temp1=a[i+1];
    a[i+1]=a[r];
    a[r]=temp1;
    return i+1;
}
