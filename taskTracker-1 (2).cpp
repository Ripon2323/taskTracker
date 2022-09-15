
#include<iostream>
#include<bits/stdc++.h>
#include<fstream>
#include<conio.h>
#include<time.h>
#include<dos.h>
#include<windows.h>
#include<MMSystem.h>
#include<string.h>
#include<stdlib.h>
#include <sstream>
#include<string>
#include<graphics.h>
#include<time.h>





using namespace std;

time_t now;
struct tm *rn;



int i,p,n,hr,mins,tday,tmon,tyear, day[500],mon[500],year[500], rem_no=0, rem_x=0, tmp_hr, dmy=0;
int t_hr[1000],t_min[1000], format_hr[1000], exp_d[500], exp_w[500], exp_m[500], exp_index=0, exp_today, exp_seven[500],exp_thirty[500];
char s[500],s2,s1[500],s3,str[500][500], ttxx[500][500], am_pm;
string text[500], tmp_text, exp_dtx[500],exp_wtx[500],exp_mtx[500];





// timediffrence

// timediffrence

class student
{
	protected:
	char message[100];
	 char time[50];
	char date[60];
	public:
	void getdata();
	void showdata();
	friend void write();


};
// global variables
int k=0;
fstream obj;
student st;
// Declaration of All non class functions
void viewall();
void mainmenu();
void deleteall();
void reminder();
void exit();

void addexp();
void totalexp();
void mail();
void digitalClock();

//Add Task

int get_file_lines(){
int number_of_lines = 0;

    string line;
    ifstream myfile("student3.txt");

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            //cout<< line << endl;
            number_of_lines++;
        }
        myfile.close();
    }


number_of_lines--;
    return  number_of_lines;
}

/*int get_file_lines1(){
int number_of_lines1 = 0;

    string line;
    ifstream myfile("student4.txt");

    if(myfile.is_open()){
        while(!myfile.eof()){
            getline(myfile,line);
            //cout<< line << endl;
            number_of_lines1++;
        }
        myfile.close();
    }


number_of_lines1--;
    return  number_of_lines1;
}*/



void write(){

		st.getdata();
}

bool rightNow(int a, int b){

int lp=1;
while(lp!=2){ lp++;
time(&now);
rn=localtime(&now);

int hour = rn->tm_hour;
int mins = rn->tm_min;

if(a>=hour) {
    if(a==hour){
     if(b>=mins) return true; else return false;
    }else return true;
        }else return false;

}


}


void student :: getdata()
{
	system("cls");

	SYSTEMTIME t;
    GetLocalTime(&t);


fix_date:
    ofstream file;
    file.open("student3.txt",ios::out|ios::app);
   // printf("Please enter a date > or = today in Day-mon-year format:\n");
   cout<<"Please enter a date > or = today in Day-mon-year format:"<<endl;
    scanf("%d-%d-%d",&tday,&tmon,&tyear);
    //cin>>tday>>tmon>>tyear;
  // file<<"Date: "<<tday<<"-"<<tmon<<"-"<<tyear<<endl;
   //file.close();
    if(tyear>=t.wYear) {
            if(tyear>t.wYear) {}
                else if  (tmon>=t.wMonth){
                    if  (tmon>t.wMonth) {}
                        else if  (tday>=t.wDay){
                        if(tday>t.wDay  ) {} else {}

                }  else goto fix_date;
                }
                else goto fix_date;
                 }
    else goto fix_date;

rem_limit:

    //printf("\n\nhow many Tasks you want to add for that day?\n");
    cout<<endl<<"how many Tasks you want to add for that day?"<<endl;
    get_file_lines();

   // scanf("%d",&n);
     cin>>n;

     if(n>100) { cout<<"max 100 Tasks per day"; goto rem_limit; }

	 for(i=(rem_no-rem_x); i<(n+rem_no-rem_x); i++)
    {
        day[i]=tday; mon[i]=tmon; year[i]=tyear;
        //printf("\n\nReminder : %d\n",i+1);
        cout<<endl<<endl<<"Reminder:"<<i+1;

    file<<"Task no:"<<(get_file_lines()+1)<<"  ";
    file<<"Date:"<<tday<<"-"<<tmon<<"-"<<tyear<<"  ";


        chk_hour:
       // printf("\nEnter hour:min\n");
        cout<<endl<<"Enter hour:min"<<endl;
        scanf("%d:%d",&hr,&mins);
      //cin>>hr>>mins;



        if(hr>12)
        { getchar();
            cout<<"Please use 12 hour format"<<endl; goto chk_hour;
        }



        if(mins>=60) {
            getchar();
            cout<<"minutes must be less than 60"<<endl; goto chk_hour;
        }





        cout<<"Please enter the time format AM or PM"<<endl;
        getchar();
        //scanf("%c%c",&s[i],&s2);
        cin>>s[i]>>s2;
        getchar();
          //file<<"Task: "<<i+1<<endl;
          file<<"Time:"<<hr<<":"<<mins<<" "<<s[i]<<s2<<endl;


        if(s[i]=='a'||s[i]=='A')
        {
            if(hr==12) {
                 format_hr[i]=hr;
                hr=hr-12;

            }
            else format_hr[i]=hr;

        }


        else  if(s[i]=='p'|| s[i]=='P'){
        if(hr<12){

            format_hr[i]=hr;
           hr=hr+12;
        }

    }

        // check if time is less than right now time

        format_hr[i]=hr;

        t_hr[i]=hr;
        t_min[i]=mins;






         cout<<"Enter the event name to remind:\n";
        gets(str[i]);

        text[i]=str[i];





    } rem_no=(n+rem_no); n=rem_no-rem_x; dmy++;

     cout<<endl<<endl<<"Tasks saved!"<<endl;


         cout<<endl<<"Press k for Main Menu"<<endl;
	if(_getch()=='k')
		mainmenu();

}



int clock(int a,int b,char str[])

{
    int j,loop=0;
    system("cls");
    while(loop!=1)
    {
        time(&now);
        rn=localtime(&now);




        if(a==rn->tm_hour & b==rn->tm_min)
        {
            tmp_text=text[0];
            for(p=0;p<n-1;p++){

            format_hr[p]=format_hr[p+1];
            t_min[p]=t_min[p+1];
            text[p]=text[p+1];

             day[p]=day[p+1];
              mon[p]=mon[p+1];
               year[p]=year[p+1];
               s[p]=s[p+1];

            }  n=n-1; rem_x++;

            if(a>12) { a=a-12; am_pm='p'; } else  am_pm='a';

            printf("Right now your event is : %s\nTime - %d:%d%cm",tmp_text.c_str(),a,b,s[0]);
            //cout<<"Right now your event is : %s\nTime - %d:%d%cm"<<tmp_text.c_str()<<a<<b<<s[0];

            mail();




            for(j=0;j<8;j++)
            {
            Beep(500,900);
            Beep(700,800); Beep(500,900); Beep(500,900); Beep(500,900); Beep(500,900); Beep(500,900); Beep(500,900); Beep(500,900);

            Sleep(1000);
            }
            //mainmenu();
            loop=1;

            //getchar(); 30 09 2021

            system("cls");


             cout<<"\n\n\n   Press k to stop and goto Main Menu\n";
	if(_getch()=='k')
		mainmenu();


        }
        else
            free(rn);

    }
}


void sort_dmy_hr_mins(){

  int tmd2=day[i];
            day[i]=day[p+1];
            day[p+1]=tmd2;

                     int tmm=mon[i];
            mon[i]=mon[p+1];
            mon[p+1]=tmm;


            int tmy=year[i];
            year[i]=year[p+1];
            year[p+1]=tmy;


            int tmp=format_hr[i];
            format_hr[i]=format_hr[p+1];
            format_hr[p+1]=tmp;



            int tmp2=t_min[i];
            t_min[i]=t_min[p+1];
            t_min[p+1]=tmp2;




            string tmp3=text[i];
            text[i]=text[p+1];
            text[p+1]=tmp3;


            char tmp4=s[i];
            s[i]=s[p+1];
            s[p+1]=tmp4;

}

void sort_rems(){


             // day month year check

            for(i=0;i<n;i++) {
	           for(p=i;p<n-1;p++) {
            if ( year[i]>year[p+1] ) {

                sort_dmy_hr_mins();


              }

              else if(year[i]==year[p+1]){
                  if(mon[i]>mon[p+1]){

                     sort_dmy_hr_mins();

                  }

                  else if(mon[i]==mon[p+1]){
                        if(day[i]>day[p+1]){

                         sort_dmy_hr_mins();

                  } }

              }



                 } }

            // day month year check


// same day check

             for(i=0;i<n;i++) {
	           for(p=i;p<n-1;p++) {
                    if(year[i]==year[p+1] && mon[i]==mon[p+1] && day[i]==day[p+1])
            if(s[i]=='p' && s[p+1]=='a') {  //cout<<format_hr[i]<<"pm....am"<<format_hr[p+1]<<endl;
            int tmp=format_hr[i];
            format_hr[i]=format_hr[p+1];
            format_hr[p+1]=tmp;

           // cout<<format_hr[i]<<"pm....am"<<format_hr[p+1]<<endl;



            int tmp2=t_min[i];
            t_min[i]=t_min[p+1];
            t_min[p+1]=tmp2;




            string tmp3=text[i];
            text[i]=text[p+1];
            text[p+1]=tmp3;


            char tmp4=s[i];
            s[i]=s[p+1];
            s[p+1]=tmp4;

            }  }   }
// ends of am->pm


 for(i=0;i<n;i++) {
	           for(p=i;p<n-1;p++) {

                if(year[i]==year[p+1] && mon[i]==mon[p+1] && day[i]==day[p+1])
            if ((s[i]=='p' && s[p+1]=='p') || (s[i]=='a' && s[p+1]=='a') )
            if(format_hr[i]>format_hr[p+1]) {
            int tmp=format_hr[i];
            format_hr[i]=format_hr[p+1];
            format_hr[p+1]=tmp;



            int tmp2=t_min[i];
            t_min[i]=t_min[p+1];
            t_min[p+1]=tmp2;




            string tmp3=text[i];
            text[i]=text[p+1];
            text[p+1]=tmp3;

            }  }   }
//
            for(i=0;i<n;i++)
             for(p=i;p<n-1;p++) {
                    if(year[i]==year[p+1] && mon[i]==mon[p+1] && day[i]==day[p+1])
                    if ((s[i]=='p' && s[p+1]=='p') || (s[i]=='a' && s[p+1]=='a') )
            if(format_hr[i]==format_hr[p+1])
                if(t_min[i]>t_min[p+1]){
            int tmp=t_min[i];
            t_min[i]=t_min[p+1];
            t_min[p+1]=tmp;



            string tmp3=text[i];
            text[i]=text[p+1];
            text[p+1]=tmp3;


            }
             }
}

void reminder(){
    //digitalClock();

   sort_rems();

     SYSTEMTIME t;
    GetLocalTime(&t);



    for(i=0;i<n;i++){
    if(tyear==t.wYear && tmon==t.wMonth && tday==t.wDay )
    {

        if(t_min[i]<10){ t_min[i]=60-(10-t_min[i]); format_hr[i]=format_hr[i]-1; }
          else t_min[i]=t_min[i]-10;

            clock(format_hr[i],t_min[i],str[i]);

    }

    else {
        printf("\nYou have no nTask today"); break;
        }

    }



     cout<<"\n\n   Press k to goto Main Menu\n";
	if(_getch()=='k')
		mainmenu();


    //mainmenu();
}

void exit(){
	system("cls");


	Sleep(3000);
	exit(0);
}

//View All Task
void viewall(){
	system("cls");


    sort_rems();




	 cout<<"Saved Tasks...\n\n";

	  ifstream file("student3.txt");
	//infile.seekg(0, ios::beg);
	//infile>>tday>>tmon>>tyear;
	string line;
	while (getline(file, line)) {

        // Read a Line from File


        // Print line in Console
        //cout<<"Date"<<tday<<"-"<<tmon<<"-"<<tyear;
        cout<<line<<endl;
    }

/*for(i=0;i<n;i++){


if(format_hr[i]>12) { tmp_hr=format_hr[i]-12; } else if(format_hr[i]==0) tmp_hr=12; else tmp_hr=format_hr[i];

           cout<<"Today Task "<<i+1<<": "<<text[i]<<endl;;
	cout<<"Time : "<<tmp_hr<<":"<<t_min[i]<<s[i]<<"m"<<endl;
	cout<<"Date : "<<day[i]<<"-"<<mon[i]<<"-"<<year[i]<<endl; cout<<"\n\n";

	cout<<"Previous Task"<<endl<<endl<<endl;

} */




	cout<<"\n\n\n   Press k for Main Menu\n";
	if(_getch()=='k')
		mainmenu();
	else viewall();
	}

// Delete Task
void deleteall(){

	system("cls"); int tasks_cnt=0, task_no;

	sort_rems();


	vector<string> records;
	string line;
	ifstream records_input("student3.txt"); // create a file stream and open the file for reading
	while (getline(records_input, line)) // read all the lines from the file and store in vector records
	{
		records.push_back(line);
	}

	records_input.close(); // close the file
	size_t recno = records.size(); // get the number of lines read

	cout << "These are the records" << endl;
	for (size_t i = 0; i < recno; ++i) // display all the lines read
	{
		cout  << records[i] << endl;
	}

	size_t recno1 = 0;
	cout << "Which record would you like to delete?" << endl;
	cin >> recno1; // get the user to pick a record

	if (recno1 < 0 || recno1 >= recno) // validate their choice
	{
		cout << "Invalid choice" << endl;
	}
	else
	{
		cout << "You have chosen to delete record " << recno1 << ": " << records[recno1] << endl;
		records.erase(records.begin() + recno1); // delete users choice from the records vector
		recno = records.size(); // the size of the vector will change
	}

	ofstream records_output("student3.txt"); // create a file stream and open the file for output
	cout << "These are the records" << endl;
	for (size_t i = 0; i < recno; ++i) // write out the new records to screen
	{
		cout << i << ": " << records[i] << endl;
		records_output << records[i] << endl;// also overwrite the original file with the new records
	}

	records_output.close(); // close the file
	cout << endl << "Goodbye" << endl;




	/* cout<<"All Tasks...\n\n";

	 //all task from file
	 ifstream file("student3.txt");
	 while (getline(file, line)) {

        cout<<line<<endl;
    }

	/*for(i=0;i<n;i++){ tasks_cnt++;
if(format_hr[i]>12) { tmp_hr=format_hr[i]-12; } else if(format_hr[i]==0) tmp_hr=12; else tmp_hr=format_hr[i];
    cout<<"Task "<<i+1<<": "<<text[i]<<endl;;
	cout<<"Time : "<<tmp_hr<<":"<<t_min[i]<<s[i]<<"m"<<endl;
	cout<<"Date : "<<day[i]<<"-"<<mon[i]<<"-"<<year[i]<<endl; cout<<"\n\n";
}*/
	//
/*	deltsk:
	    cout<<"\n\n\t\t press k for main menu d for continue delete.."<<endl;
	if(_getch()=='k'){
	//Sleep(2000);
	mainmenu();
	} else
	cout<<"\n\n\t\t Press the task number you want to delete.. "<<endl;
	 scanf("%d",&task_no);





	/* if(task_no<=tasks_cnt){

        for(i=0;i<n;i++){
         if(task_no==(i+1)){
          for(p=task_no-1;p<n-1;p++){

          format_hr[p]=format_hr[p+1];
            t_min[p]=t_min[p+1];
            text[p]=text[p+1];

             day[p]=day[p+1];
              mon[p]=mon[p+1];
               year[p]=year[p+1];
               s[p]=s[p+1];


          } n=n-1;

         }

        }


	 } else{cout<<"\n\t\tInvalid task number!\n "<<endl; goto deltsk;}*/






cout<<"\n\n\t\t Task deleted!!!"<<endl;
	///
	cout<<"\n\n\t\t press k for main menu "<<endl;
	if(_getch()=='k'){
	//Sleep(2000);
	mainmenu();
	}
	else
		deleteall();
}


/*void deleteall(){

	system("cls"); int tasks_cnt=0, task_no;

	sort_rems();

	 cout<<"All Tasks...\n\n";
	for(i=0;i<n;i++){ tasks_cnt++;
if(format_hr[i]>12) { tmp_hr=format_hr[i]-12; } else if(format_hr[i]==0) tmp_hr=12; else tmp_hr=format_hr[i];
    cout<<"Task "<<i+1<<": "<<text[i]<<endl;;
	cout<<"Time : "<<tmp_hr<<":"<<t_min[i]<<s[i]<<"m"<<endl;
	cout<<"Date : "<<day[i]<<"-"<<mon[i]<<"-"<<year[i]<<endl; cout<<"\n\n";
}
	//
	deltsk:
	    cout<<"\n\n\t\t press k for main menu d for continue delete.."<<endl;
	if(_getch()=='k'){
	//Sleep(2000);
	mainmenu();
	} else
	cout<<"\n\n\t\t Press the task number you want to delete.. "<<endl;
	 scanf("%d",&task_no);
	 if(task_no<=tasks_cnt){

        for(i=0;i<n;i++){
         if(task_no==(i+1)){
          for(p=task_no-1;p<n-1;p++){

          format_hr[p]=format_hr[p+1];
            t_min[p]=t_min[p+1];
            text[p]=text[p+1];

             day[p]=day[p+1];
              mon[p]=mon[p+1];
               year[p]=year[p+1];
               s[p]=s[p+1];


          } n=n-1;

         }

        }


	 } else{cout<<"\n\t\tInvalid task number!\n "<<endl; goto deltsk;}

cout<<"\n\n\t\t Task deleted!!!"<<endl;
	///
	cout<<"\n\n\t\t press k for main menu "<<endl;
	if(_getch()=='k'){
	//Sleep(2000);
	mainmenu();
	}
	else
		deleteall();
}*/


//Add exp
void addexp(){ system("cls");  SYSTEMTIME t; GetLocalTime(&t);
     ofstream data_in;
     ofstream data_inp;
    data_in.open("student4.txt",ios::out|ios::app);
    data_inp.open("student5.csv",ios::out|ios::app);
//    get_file_lines1();

   int arrSize = i;
  int total_d_exp=0;
   for(i=0;exp_m[i]!=NULL;i++){}
                 exp_index=i;

                // printf("")

  cout<<"Please enter a date > or = today in Day-mon-year format:"<<endl;
    scanf("%d-%d-%d",&tday,&tmon,&tyear);

  printf("\nEnter Expense amount\n");
        scanf("%d",&exp_d[exp_index]);

        exp_w[exp_index]=exp_d[exp_index];
        exp_m[exp_index]=exp_d[exp_index];

            getchar();

         printf("\nType Expense purpose..\n");
        gets(ttxx[exp_index]);
                exp_dtx[exp_index]=ttxx[exp_index];
                exp_wtx[exp_index]=exp_dtx[exp_index];
                exp_mtx[exp_index]=exp_dtx[exp_index];
        // data_in<<"Expense No:"<<endl;
        // data_in<<"    "<< (get_file_lines1()/6)+1<<endl;
         data_in<<"Expense:"<<endl;
         data_in<<"    "<<exp_d[exp_index]<<endl;
         data_in<<"Purpose:"<<endl;
         data_in<<"    "<<ttxx[exp_index]<<endl;

         //excell input
         data_inp<<"Date"<<","<<"Expense"<<","<<"Purpose"<<endl;
         data_inp<<tday<<"-"<<tmon<<"-"<<tyear<<","<<exp_d[exp_index]<<","<<ttxx[exp_index]<<endl;
         //file<<"Date:"<<tday<<"-"<<tmon<<"-"<<tyear<<"  ";
         //data_inp<<"Purpose:"<<endl;
        // data_inp<<"    "<<ttxx[exp_index]<<endl;



//getchar();
            exp_today=t.wDay; exp_seven[exp_index]=t.wDay, exp_thirty[exp_index]=t.wMonth;
            for(i=0;i<arrSize;i++){
         total_d_exp=total_d_exp+exp_d[i];
        // myfile<<"Total:"<<total_d_exp<<endl;
            }
         printf("\n\nExpense saved!\n");
         cout<<"\n Press k for Main Menu\n";
	     if(_getch()=='k')
		 mainmenu();

}




// Daiy, weekly, monthly Expenses
void exp_day(){ system("cls");  SYSTEMTIME t; GetLocalTime(&t);
ifstream data_in("student4.txt");

cout<<"Today's Expenses:\n\n\n";

for(i=0;exp_d[i]!=NULL;i++){}
int arrSize = i;
int total_d_exp=0;
//if(t.wDay!=exp_today){ arrSize=0; printf("No expense to show!"); }

 for(i=0;i<arrSize;i++){
 cout<<"Expense "<<i+1<<":\nPurpose:"<<exp_dtx[i]<<"\nAmount:"<<exp_d[i]<<"\n\n";  total_d_exp=total_d_exp+exp_d[i];
}


if(data_in.is_open())
    {
        string name1;
        int v1;
        string name2;
        int v2;
        string name3;
        string name4;
        //string line;
        int total=0;
       //int lines= get_file_lines();
        //get_file_lines();
        while(data_in>>name2>>v2>>name3>>name4)
        {
            //cout<<x<<" ";
                 //cout<<name1<<v1<<endl;
                 cout<<name2<<v2<<"     "<<name3<<name4<<endl;


               /* cout<<name1<<endl;
                cout<<v<<endl;
                cout<<name<<endl;
                cout<<name2<<endl;*/
                total=total+v2;

        }
        cout<<endl<<endl<<endl<<"Total:"<<total;


       data_in.close();
       //cin.get();

    }


 //printf("-----------------------------------------------------------------------------------------\nTotal Expense = %d",total_d_exp);
cout<<"\n\n Press k for Main Menu\n";
	     if(_getch()=='k')
		 mainmenu();
}



//...............
/*void exp_day(){ system("cls");  SYSTEMTIME t; GetLocalTime(&t);
   // ofstream infile;
//    infile.open("student4.txt",ios::out|ios::app);
ifstream myfile1("student4.txt");
cout<<"Today's Expenses:\n\n\n";
/*for(i=0;exp_d[i]!=NULL;i++){}
int arrSize = i;
int total_d_exp=0;
//if(t.wDay!=exp_today){ arrSize=0; printf("No expense to show!"); }




if(myfile1.is_open())
    {
        int v;
        string name;
        string line;
        int total=0;
       //int lines= get_file_lines();
        //get_file_lines();
        while(myfile1>>v>>name)
        {
            //cout<<x<<" ";

                cout<<v<<endl;
                cout<<name<<endl;
                total=total+v;

        }
        cout<<"Total:"<<total;


       myfile1.close();

    }
   // cin.get();//  cout<<line<<endl;

//}
 /*for(i=0;i<arrSize;i++){
 cout<<"Expense "<<i+1<<":\nPurpose:"<<exp_dtx[i]<<"\nAmount:"<<exp_d[i]<<"\n\n";  total_d_exp=total_d_exp+exp_d[i];
}
// printf("-----------------------------------------------------------------------------------------\nTotal Expense = %d",total_d_exp);
cout<<"\n\n Press k for Main Menu\n";

	     if(_getch()=='k')
		 mainmenu();
}*/

void exp_week(){ system("cls"); SYSTEMTIME t; GetLocalTime(&t);

for(i=0;exp_w[i]!=NULL;i++){}
int arrSize2 = i;

int total_w_exp=0;

for(p=0;p<500; p++)
    if(t.wDay-exp_seven[i]==7 || t.wDay-exp_seven[i]==(-23) ){ for(i=0;i<arrSize2;i++){
 cout<<"Expense "<<i+1<<":\nPurpose:"<<exp_wtx[i]<<"\nAmount:"<<exp_w[i]<<"\n\n";  total_w_exp=total_w_exp+exp_w[i];
} }

if(total_w_exp==0){
cout<<"Weekly expense will be available when week ends:\n";
cout<<"\n\n Press k for Main Menu\n";
	     if(_getch()=='k')
		 mainmenu();
}

}


void exp_mon(){ system("cls"); SYSTEMTIME t; GetLocalTime(&t);
for(i=0;exp_m[i]!=NULL;i++){}
int arrSize3 = i;

int total_m_exp=0;

for(p=0;p<500; p++)
    if(t.wMonth!=exp_thirty[i] && exp_thirty[i]!=NULL){ for(i=0;i<arrSize3;i++){
 cout<<"Expense "<<i+1<<":\nPurpose:"<<exp_mtx[i]<<"\nAmount:"<<exp_m[i]<<"\n\n";  total_m_exp=total_m_exp+exp_m[i];
} }

if(total_m_exp==0){
cout<<"Monthly expense will be available when Month ends:\n";
cout<<"\n\n Press k for Main Menu\n";
	     if(_getch()=='k')
		 mainmenu();
}

}


//Total exp
void totalexp(){ system("cls");
cout<<" \n\t\t 1.Daily Expense\n\t\t 2.Weekly Expense\n\t\t 3.Monthly Expense\n\t\t 4.Main menu";
	char chr;
	switch(chr=_getch()){

	case '1':
		exp_day();
		break;
   case '2':
		exp_week();
		break;
	case '3':
	    exp_mon();
	    break;
    case '4':
	    mainmenu();
	    break;

	default :
		totalexp();
		break;
	}
}


void mainmenu(){

	system("cls");
        cout<<" \n\t\t 1. Add Tasks\n\t\t 2. View All Tasks\n\t\t 3. Delete Tasks\n\t\t 4. Add today's expense\n\t\t 5. View total expense\n\t\t  6. Exit\n\t\t  7.Clock\n\n";
		cout<<"\t\t Please select from the above: ";

	char ch;
	switch(ch=_getch()){

	case '1':
		write();
		break;
	case '2':
		viewall();
		break;
	case '3':
	    deleteall();
		break;
            case '4':
	    addexp();
		break;
		case '5':
	    totalexp();
		break;
	case '6':
		exit();
		break;

		/*case '7':
		reminder();
		break;*/
		case '7':
		digitalClock();

	default :
		mainmenu();
		break;
	}
}


void mail(){
    //printf("mail");
    char* command = "curl smtp://smtp.gmail.com:587 -v --mail-from \"tottenham266@gmail.com\" --mail-rcpt \"ripon23.hawladar@gmail.com\" --ssl -u tottenham266:yjwwkbkylymnvbrs -T \"test.txt\" -k --anyauth";
    WinExec(command, SW_HIDE);

}

void digitalClock()
{


    int gd=DETECT;
    int gm;
    initgraph(&gd,&gm,"C:\\rc\\BGI");


    time_t rawTime;
    struct tm * currentTime;
    char a[100];


              while(1){
     rawTime=time(NULL);
    currentTime=localtime(&rawTime);
    strftime(a,100,"%I:%M:%S",currentTime);

    setcolor(11);
    settextstyle(3,HORIZ_DIR,10);
    outtextxy(200,100,a);

    strftime(a,100,"%p",currentTime);
    settextstyle(3,HORIZ_DIR,2);
    outtextxy(600,8,a);

    strftime(a,100,"%a,%d %b,%Y",currentTime);
    settextstyle(3,HORIZ_DIR,5);
    outtextxy(130,310,a);
      delay(1000);
        }

    }






   // getch();
    //closegraph();


	int main()
	{
		mainmenu(); cout<<"\a";
		sort_rems();
      // alarm A;  A.getTime(19,15);  A.start_alarm(); 01 10 2021
		_getch();
		return 0;

	}


