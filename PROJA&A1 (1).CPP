#include<fstream.h>
#include<conio.h>
#include<string.h>
#include<stdio.h>
class plane
{
 int eseats,bseats,pattendno;
 char pcode[25],ptype[40],pcomp[20],from[50],to[50],airport[80],terminal[50];
 char days[80];
 float duration;
 double price;
 public:
void getd();
void getd1();
void show();
char* retcomp() {return pcomp;}
char* rettype() {return ptype;}
char* retcode() {return pcode;}
char* retairp() {return airport;}
char* retterm() {return terminal;}
char* retto() {return to;}
char* retfrom() {return from;}
float retprice() {return price;}

};
void kyf(){cout<<"\n\t\t\t\tKNOW YOUR FLIGHT\n\n";}
void plane::getd()
{
  kyf();
  cout<<"1.Enter:Place of departure\n";
	gets(from);
  cout<<"2.Enter:Place of arrival\n";
	gets(to);
  cout<<"3.Enter:Company of plane\n";
	gets(pcomp);
  cout<<"4.Enter:Plane code\n";
	gets(pcode);
  cout<<"5.Enter:Plane type\n";
	gets(ptype);
  cout<<"6.Enter:Days of flight\n";
	gets(days);
  cout<<"7.Enter:Airport\n";
	gets(airport);
  cout<<"8.Enter:Terminal\n";
	gets(terminal);
  cout<<"9.Enter:no. of economy seats\n";
	cin>>eseats;
  cout<<"10.Enter:no. of business seats\n";
	cin>>bseats;
  cout<<"11.Enter:No.of attendants\n";
	cin>>pattendno;
  cout<<"12.Enter:Price of flight(INR)\n";
	cin>>price;
  cout<<"13.Enter:Duration(HOURS)\n";
	cin>>duration;
}
void plane::getd1()
{
  kyf();
  cout<<"1.Enter:Place of departure";
	gets(from);
  cout<<"2.Enter:Place of arrival";
	gets(to);
  cout<<"3.Enter:Company of plane";
	gets(pcomp);
  cout<<"4.Enter:Plane type";
	gets(ptype);
  cout<<"5.Enter:Days of flight";
	gets(days);
  cout<<"6.Enter:Airport";
	gets(airport);
  cout<<"7.Enter:Terminal";
	gets(terminal);
  cout<<"8.Enter:no. of economy seats";
	cin>>eseats;
  cout<<"9.Enter:no. of business seats";
	cin>>bseats;
  cout<<"10.Enter:No.of attendants";
	cin>>pattendno;
  cout<<"11.Enter:Price of flight";
	cin>>price;
  cout<<"12.Enter:Duration";
	cin>>duration;
}
void plane::show()
{
  kyf();
  cout<<"Place of departure-"<<from<<"\n"<<"Place of arrival-"<<to<<"\n";
  cout<<"Company of plane-"<<pcomp<<"\n";
  cout<<"no. of economy seats-"<<eseats<<"\n";
  cout<<"no. of business seats-"<<bseats<<"\n";
  cout<<"No.of attendants-"<<pattendno<<"\n";
  cout<<"Plane code-";puts(pcode);
  cout<<"Plane type-";puts(ptype);
  cout<<"Price of flight-"<<price<<"\n"<<"Duration-"<<duration<<"\n";
  cout<<"Airport-";puts(airport);
  cout<<"Terminal-";puts(terminal);
  cout<<"Days-";puts(days);
}
fstream f;
void create()
{
 kyf();
 f.open("Plane.dat",ios::out|ios::binary);
 if(!f)
  {
   cout<<"Error in file opening\n";
   return;
  }
 plane p1;
 char ans='y';
 do
 {
  p1.getd();
  f.write((char *)&p1,sizeof(p1));
  cout<<" Do you want to enter another record?(y/n)";
  cin>>ans;
 }while(ans=='y'||ans=='Y');
 f.close();
}
void readall()
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;
  while(f.read((char*)&p1,sizeof(p1)))
   p1.show();
  f.close();
}
void countall()
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
   {
    ctr++;
   }
  f.close();
  cout<<ctr;
}
void searchcomp(char s[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(s,p1.retcomp())==0)
      {
      ctr++;
      p1.show();
      }
  }
    if (ctr==0)
    cout<<"Company not found";
  f.close();
}

void searchpcode(char pco[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
    if (strcmpi(p1.retcode(),pco)==0)
    {
     p1.show();
     ctr++;
     break;
    }
  }
    if (ctr==0)
    cout<<" not found";
  f.close();
}
void searchpriceg(float pr)
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
    if (p1.retprice()>=pr)
    {
     p1.show();
     ctr++;
     break;
    }
  }
    if (ctr==0)
    cout<<" not found";
  f.close();
}

void searchpricel(float pr)
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
    if (p1.retprice()<=pr)
    {
     p1.show();
     ctr++;
     break;
    }
  }
    if (ctr==0)
    cout<<" not found";
  f.close();
}

void searchtype(char p[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.rettype(),p)==0)
    {
     p1.show();
     ctr++;
    }
  }
    if (ctr==0)
    cout<<"Record not found";
  f.close();
}
void searchairport(char a[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.retairp(),a)==0)
    {
     p1.show();
     ctr++;
    }
  }
    if (ctr==0)
    cout<<"Record not found";
  f.close();
}
void searchterm(char te[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.retterm(),te)==0)
    {
     p1.show();
     ctr++;
    }
  }
    if (ctr==0)
    cout<<"Record not found";
  f.close();
}
void searchto(char to[],char from[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.retto(),to)==0 && strcmpi(p1.retfrom(),from)==0)
      {
      ctr++;
      p1.show();
      }
  }
    if (ctr==0)
    cout<<"Flight not found";
  f.close();
}
void countcomp(char s[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(s,p1.retcomp())==0)
      {
      ctr++;
      }
  }
  cout<<ctr<<"=number of planes\n";
  f.close();
}
void countterm(char te[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.retterm(),te)==0)
    {
     ctr++;
    }
  }
  cout<<ctr<<"=number of planes\n";
  f.close();
}
void counttype(char p[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.rettype(),p)==0)
    {
     ctr++;
    }
  }cout<<ctr<<"=number of planes\n";
  f.close();
}
void countairport(char a[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.retairp(),a)==0)
    {
     ctr++;
    }
  } cout<<ctr<<"=number of planes\n";
  f.close();
}
void countto(char to[],char from[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
   if(strcmpi(p1.retto(),to)==0 && strcmpi(p1.retfrom(),from)==0)
      {
      ctr++;
      }
  }
  cout<<ctr<<"=number of planes\n";
  f.close();
}
void countpriceg(float pr)
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
    if (p1.retprice()>=pr)
    {
     ctr++;
     break;
    }
  }
  cout<<ctr<<"=number of planes\n";
  f.close();
}
void countpricel(float pr)
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
  {
    if (p1.retprice()<=pr)
    {
     ctr++;
     break;
    }
  }
  cout<<ctr<<"=number of planes\n";
  f.close();
}
void insfst()
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
   if(!f)
  {
   cout<<"Error in file opening\n";
   return;
  }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1; p1.getd();
  while(f.read((char *)&p1,sizeof(p1)))
    f1.write((char *)&p1,sizeof(p1));
    f.close(); f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
}
void inslst()
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;
  while(f.read((char *)&p1,sizeof(p1)))
    f1.write((char *)&p1,sizeof(p1));
    p1.getd();
    f1.write((char *)&p1,sizeof(p1));
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
}
void insnth(int n)
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1,p;int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
   {
    ctr++;
    if (ctr==n)
    {
     p1.getd();
     f1.write((char *)&p1,sizeof(p1));
    }
    f1.write((char *)&p,sizeof(p1));
   }
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
}
void inspcode(char pc[5])
{
  kyf();
  plane p1,p;
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  while(f.read((char *)&p1,sizeof(p1)))
   {
    f1.write((char *)&p1,sizeof(p1));
    if(strcmpi(p1.retcode(),pc)==0)
    {
     p1.getd();
     f1.write((char *)&p,sizeof(p1));
    }
   }
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
}

void editpos(int rec)
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  plane p1;int r=0;
  while(f.read((char *)&p1,sizeof(p1)))
   {
    r++;
    if (r==rec)
     p1.getd1();
     f1.write((char *)&p1,sizeof(p1));
   }
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
}
void editcode(char cd[])
{
  kyf();
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"\nerror in file opening\n";
   return;
   }
  ofstream fout("temp.dat",ios::binary);
  if(!fout)
   {
   cout<<"\nerror in file opening\n";
  return;
   }
  plane p1;
  int ctr=0;
  while(f.read((char*)&p1,sizeof(p1)))
   {
    ctr++;
    if(strcmpi(p1.retcode(),cd)==0)
   {
    f.seekg(-1*sizeof(p1),ios::cur);
    cout<<"\nenter details of record to edit(enter all details, even if some are same.)\n";
    p1.getd();
   }
   fout.write((char*)&p1,sizeof(p1));
  break;
  }
 if(ctr==0)
  cout<<"not found";
 fout.close();
 f.close();
 remove("Plane.dat");
 rename("temp.dat","Plane.dat");
}

void delfst()
{
  kyf();
  plane p1;
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  f.seekg(sizeof(p1));
  while(f.read((char *)&p1,sizeof(p1)))
    f1.write((char *)&p1,sizeof(p1));
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
    cout<<"\nYour record has been deleted\n";
}
void dellst()
{
  kyf();
  plane p1;
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  f.seekg(0,ios::end);int totrec=f.tellg()/sizeof(p1);
  int ctr=0; f.seekg(0);
  while(f.read((char *)&p1,sizeof(p1)))
   {
    ctr++;
    if(ctr!=totrec)
    f1.write((char *)&p1,sizeof(p1));
   }
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
   cout<<"\nYour record has been deleted\n";
}
void delnth(int n)
{
  kyf();
  plane p1;
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  int ctr=0;
  while(f.read((char *)&p1,sizeof(p1)))
   {
    ctr++;
    if(ctr!=n)
    f1.write((char *)&p1,sizeof(p1));
   }
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
    cout<<"\nYour record has been deleted\n";
}
void delpcode(char pc[5])
{
  plane p1;
  f.open("Plane.dat",ios::in|ios::binary);
  if(!f)
   {
    cout<<"Error in file opening\n";
    return;
   }
  ofstream f1("temp.dat",ios::binary);
  if(!f1)
   {
    cout<<"Error in file opening\n";
    return;
   }
  while(f.read((char *)&p1,sizeof(p1)))
   {
    if(strcmpi(p1.retcode(),pc)==0)
    f1.write((char *)&p1,sizeof(p1));
   }
    f.close();  f1.close();
    remove("Plane.dat");
    rename("temp.dat","Plane.dat");
    cout<<"\nYour record has been deleted\n";
 }
void main()
 {
   clrscr();
   kyf();
   int ch,ch1,n,r,fno,dn;float min,max;
   char ans='y';
   char pc[5],comp[10],code[5],type[10],airpo[20],to[20],fro[20],termin[4];
 do
  {
   cout<<"\t\t\t\t  WELCOME USER\n";
   cout<<"MENU:";
   cout<<"1.Create file\n";
   cout<<"2.Read all files\n";
   cout<<"3.Search\n";
   cout<<"4.Count\n";
   cout<<"5.Insert record\n";
   cout<<"6.Edit\n";
   cout<<"7.Delete record\n";
   cout<<"Enter your choice-";
   cin>>ch;
   switch(ch)
    {
     case 1: create();
	     break;
     case 2: readall();
	     break;
     case 3: kyf();
	     cout<<"1.Search on basis of Plane code\n";
	     cout<<"2.Search on basis of Plane company\n";
	     cout<<"3.Search on basis of Plane type\n";
	     cout<<"4.Search on basis of Airport\n";
	     cout<<"5.Search on basis of Terminal\n";
	     cout<<"6.Search on basis of Price greater\n";
	     cout<<"7.Search on basis of Price less than\n";
	     cout<<"8.Search on basis of Departure and Arrival\n";
	     cout<<"Enter your choice";
	     cin>>ch1;
	     switch(ch1)
	      {
	       case 1:cout<<"Enter Plane code to search\n";gets(code);
		      searchpcode(code);
		      break;
	       case 2:cout<<"Enter Plane company to search\n";gets(comp);
		      searchcomp(comp);
		      break;
	       case 3:cout<<"Enter Plane type to search\n";gets(type);
		      searchtype(type);
		      break;
	       case 4:cout<<"Enter Airport to search\n";gets(airpo);
		      searchairport(airpo);
		      break;
	       case 5:cout<<"Enter Terminal to search\n";gets(termin);
		      searchterm(termin);
		      break;
	       case 6:cout<<"Enter Minimum price to search\n";cin>>min;
		      searchpriceg(min);
		      break;
	       case 7:cout<<"Enter Maximum price to search\n";cin>>max;
		      searchpricel(max);
		      break;
	       case 8:cout<<"Enter Departure \n";gets(fro);
		      cout<<"Enter Arrival \n";gets(to);
		      searchto(to,fro);
		      break;
	      }
	     break;
     case 4:kyf();
	    cout<<"1.Count on basis of Plane company\n";
	    cout<<"2.Count on basis of Plane type\n";
	    cout<<"3.Count on basis of Airport\n";
	    cout<<"4.Count on basis of Terminal\n";
	    cout<<"5.Count on basis of Departure and Arrival\n";
	    cout<<"6.Count on basis of Minimum price\n";
	    cout<<"Enter your choice";
	    cin>>ch1;
	    switch(ch1)
	      {
	       case 1:cout<<"Enter Plane company to count\n";gets(comp);
		      countcomp(comp);
		      break;
	       case 2:cout<<"Enter Plane type to count\n";gets(type);
		      counttype(type);
		      break;
	       case 3:cout<<"Enter Airport to count\n";gets(airpo);
		      countairport(airpo);
		      break;
	       case 4:cout<<"Enter Terminal to count\n";gets(termin);
		      countterm(termin);
		      break;
	       case 5:cout<<"Enter Departure \n";gets(fro);
		      cout<<"Enter Arrival \n";gets(to);
		      countto(to,fro);
		      break;
	       case 6:cout<<"Enter Minimum price to search\n";cin>>min;
		      countpriceg(min);
		      break;
	       case 7:cout<<"Enter Maximum price to search\n";cin>>max;
		      countpricel(max);
		      break;
	      }
	     break;
     case 5:kyf();
	    cout<<"1.Insert record at first position\n";
	    cout<<"2.Insert record at last position\n";
	    cout<<"3.Insert record at nth position\n";
	    cout<<"Enter your choice";
	    cin>>ch1;
	    switch(ch1)
	      {
	       case 1:insfst();
		      break;
	       case 2:inslst();
		      break;
	       case 3:cout<<"Enter position to add record\n";
		      cin>>n;
		      insnth(n);
		      break;
	      }
	     break;
     case 6:kyf();
	    cout<<"1.Edit record based on position\n";
	    cout<<"2.Edit records based on flight code\n";
	    cin>>ch1;
	    switch (ch1)
	      {
		case 1:cout<<"Enter record number";
		       cin>>r;
		       editpos(r);
		       break;
		case 2:cout<<"Enter Flight code to edit\n";
		       gets(code);
		       editcode(code);
		       break;
	      }
	    break;
     case 7:kyf();
	    cout<<"1.Delete record at first position\n";
	    cout<<"2.Delete record at last position\n";
	    cout<<"3.Delete record at nth position\n";
	    cout<<"4.Enter flight code to delete record\n";
	    cout<<"Enter your choice";
	    cin>>ch1;
	    switch(ch1)
	      {
	       case 1:delfst();
		      break;
	       case 2:dellst();
		      break;
	       case 3:cout<<"Enter position to delete record\n";
		      cin>>dn;
		      delnth(dn);
		      break;
	       case 4:cout<<"Enter flight code to delete record\n";
		      cin>>pc;
		      delpcode(pc);
		      break;
	     }
	    break;

     }
     cout<<"Want to continue y/n?\n";
     cin>>ans;
 }while (ans=='y'||ans=='Y');
 }
 /*                            KNOW YOUR FLIGHT

				 WELCOME USER

MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-1

				KNOW YOUR FLIGHT

1.Enter:Place of departure
DELHI
2.Enter:Place of arrival
MUMBAI
3.Enter:Company of plane
AIR INDIA
4.Enter:Plane code
AI4312
5.Enter:Plane type
BOEING 707
6.Enter:Days of flight
MONDAY TUESDAY SATURDAY
7.Enter:Airport
IGI
8.Enter:Terminal
TERMINAL1
9.Enter:no. of economy seats
100
10.Enter:no. of business seats
25
11.Enter:No.of attendants
10
12.Enter:Price of flight(INR)
7500
13.Enter:Duration(HOURS)
2.5
 Do you want to enter another record?(y/n)N
Want to continue y/n?
Y
				KNOW YOUR FLIGHT

1.Enter:Place of departure
DELHI
2.Enter:Place of arrival
MUMBAI
3.Enter:Company of plane
EMIRATES
4.Enter:Plane code
EM5768
5.Enter:Plane type
AIRBUS A380
6.Enter:Days of flight
MONDAY WEDNESDAY SUNDAY
7.Enter:Airport
IGI
8.Enter:Terminal
TERMINAL3
9.Enter:no. of economy seats
300
10.Enter:no. of business seats
50
11.Enter:No.of attendants
25
12.Enter:Price of flight(INR)
27000
13.Enter:Duration(HOURS)
11.5
 Do you want to enter another record?(y/n)Y
Y
				KNOW YOUR FLIGHT

1.Enter:Place of departure
JAIPUR
2.Enter:Place of arrival
GOA
3.Enter:Company of plane
SPICEJET
4.Enter:Plane code
SJ3564
5.Enter:Plane type
BOIENG 707
6.Enter:Days of flight
TUESDAY THURSDAY
7.Enter:Airport
JAIPUR AIRPORT
8.Enter:Terminal
TERMINAL 2
9.Enter:no. of economy seats
100
10.Enter:no. of business seats
25
11.Enter:No.of attendants
7
12.Enter:Price of flight(INR)
5300
13.Enter:Duration(HOURS)
2
 Do you want to enter another record?(y/n)N
Want to continue y/n?
Y
				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-2

				KNOW YOUR FLIGHT
Place of departure-DELHI
Place of arrival-MUMBAI
Company of plane-AIR INDIA
no. of economy seats-100
no. of business seats-25
No.of attendants-10
Plane code-AI4312
Plane type-BOEING 707
Price of flight-7500
Duration-2.5
Airport-IGI
Terminal-TERMINAL1
Days-MONDAY TUESDAY SATURDAY
				KNOW YOUR FLIGHT

Place of departure-DELHI
Place of arrival-LONDON
Company of plane-EMIRATES
no. of economy seats-300
no. of business seats-50
No.of attendants-25
Plane code-EM5768
Plane type-AIRBUS A380
Price of flight-27000
Duration-11.5
Airport-IGI
Terminal-TERMINAL3
Days-MONDAY WEDNESDAY SUNDAY

				KNOW YOUR FLIGHT

Place of departure-JAIPUR
Place of arrival-GOA
Company of plane-SPICEJET
no. of economy seats-100
no. of business seats-25
No.of attendants-7
Plane code-SJ3564
Plane type-BOEING 707
Price of flight-5300
Duration-2
Airport-JAIPUR AIRPORT
Terminal-TERMINAL1
Days-TUESDAY THURSDAY
Want to continue y/n?
Y

				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-3

				KNOW YOUR FLIGHT

1.Search on basis of Plane code
2.Search on basis of Plane company
3.Search on basis of Plane type
4.Search on basis of Airport
5.Search on basis of Terminal
6.Search on basis of Price greater
7.Search on basis of Price less than
8.Search on basis of Departure and Arrival
Enter your choice1
Enter Plane code to search
AI4312

				KNOW YOUR FLIGHT


				KNOW YOUR FLIGHT

Place of departure-DELHI
Place of arrival-MUMBAI
Company of plane-AIR INDIA
no. of economy seats-100
no. of business seats-25
No.of attendants-10
Plane code-AI4312
Plane type-BOEING 707
Price of flight-7500
Duration-2.5
Airport-IGI
Terminal-TERMINAL2
Days-MONDAY TUESDAY SATURDAY
Want to continue y/n?
Y

				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-3

				KNOW YOUR FLIGHT

1.Search on basis of Plane code
2.Search on basis of Plane company
3.Search on basis of Plane type
4.Search on basis of Airport
5.Search on basis of Terminal
6.Search on basis of Price greater
7.Search on basis of Price less than
8.Search on basis of Departure and Arrival
Enter your choice2
Enter Plane company to search
EMIRATES

				KNOW YOUR FLIGHT


				KNOW YOUR FLIGHT

Place of departure-DELHI
Place of arrival-LONDON
Company of plane-EMIRATES
no. of economy seats-300
no. of business seats-50
No.of attendants-25
Plane code-EM5768
Plane type-AIRBUS A380
Price of flight-27000
Duration-11.5
Airport-IGI
Terminal-TERMINAL3
Days-MONDAY WEDNESDAY SUNDAY
Want to continue y/n?
Y

				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-3

				KNOW YOUR FLIGHT

1.Search on basis of Plane code
2.Search on basis of Plane company
3.Search on basis of Plane type
4.Search on basis of Airport
5.Search on basis of Terminal
6.Search on basis of Price greater
7.Search on basis of Price less than
8.Search on basis of Departure and Arrival
Enter your choice7
Enter Maximum price to search
7000

				KNOW YOUR FLIGHT


				KNOW YOUR FLIGHT

Place of departure-JAIPUR
Place of arrival-GOA
Company of plane-SPICEJET
no. of economy seats-100
no. of business seats-25
No.of attendants-7
Plane code-SJ3564
Plane type-BOEING 707
Price of flight-5300
Duration-2
Airport-JAIPUR AIRPORT
Terminal-TERMINAL1
Days-TUESDAY THURSDAY
Want to continue y/n?
Y


				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-4

				KNOW YOUR FLIGHT

1.Count on basis of Plane company
2.Count on basis of Plane type
3.Count on basis of Airport
4.Count on basis of Terminal
5.Count on basis of Departure and Arrival
6.Count on basis of Minimum price
Enter your choice4
Enter Terminal to count
TERMINAL1

				KNOW YOUR FLIGHT

1=number of planes
Want to continue y/n?
Y

				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-
4

				KNOW YOUR FLIGHT

1.Count on basis of Plane company
2.Count on basis of Plane type
3.Count on basis of Airport
4.Count on basis of Terminal
5.Count on basis of Departure and Arrival
6.Count on basis of Minimum price
Enter your choice5

				KNOW YOUR FLIGHT

Enter Departure
DELHI
Enter Arrival
MUMBAI

				KNOW YOUR FLIGHT

1=number of planes
Want to continue y/n?
Y

				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-
5
				KNOW YOUR FLIGHT

1.Insert record at first position
2.Insert record at last position
3.Insert record at nth position
Enter your choice-1

				KNOW YOUR FLIGHT

1.Enter:Place of departure
DELHI
2.Enter:Place of arrival
HYDERABAD
3.Enter:Company of plane
VISTARA
4.Enter:Plane code
VI3456
5.Enter:Plane type
AIRBUS320
6.Enter:Days of flight
WEDNESDAY SUNDAY
7.Enter:Airport
IGI
8.Enter:Terminal
TERMINAL1
9.Enter:no. of economy seats
150
10.Enter:no. of business seats
25
11.Enter:No.of attendants
15
12.Enter:Price of flight(INR)
2500
13.Enter:Duration(HOURS)
3.5
Want to continue y/n?
Y

				KNOW YOUR FLIGHT


MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-
6
				KNOW YOUR FLIGHT

1.Edit record based on position
2.Edit records based on flight code
1
Enter record number2

				KNOW YOUR FLIGHT


				KNOW YOUR FLIGHT

1.Enter:Place of departure
NEW YORK
2.Enter:Place of arrival
DUBAI
3.Enter:Company of plane
LUFTHANSA
4.Enter:Plane type
AIRBUSA380
5.Enter:Days of flight
SATURDAY
6.Enter:Airport
JFK
7.Enter:Terminal
TERMINAL 2D
8.Enter:no. of economy seats
200
9.Enter:no. of business seats
35
10.Enter:No.of attendants
25
11.Enter:Price of flight
30000
12.Enter:Duration14
Want to continue y/n?
Y
				  WELCOME USER
MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-7

				KNOW YOUR FLIGHT

1.Delete record at first position
2.Delete record at last position
3.Delete record at nth position
4.Enter flight code to delete record
Enter your choice2

				KNOW YOUR FLIGHT


Your record has been deleted
Want to continue y/n?
Y
				  WELCOME USER
MENU:1.Create file
2.Read all files
3.Search
4.Count
5.Insert record
6.Edit
7.Delete record
Enter your choice-7

				KNOW YOUR FLIGHT

1.Delete record at first position
2.Delete record at last position
3.Delete record at nth position
4.Enter flight code to delete record
Enter your choice4
Enter flight code to delete record
VI3456

Your record has been deleted
Want to continue y/n?
N

*/

