
#include<bits/stdc++.h>
using namespace std;
class final_messege;
int dummy=0;
int m=0,temp=0,flag=0,random=2207250;
int i=0,loop_control=0;
string tm1="10.30 AM",tm2="01.30 PM";

class applicability
{
    float gpa,physics,chemistry,math;
public:
    applicability()
    {
    }
    applicability(float g,float p,float c,float m)
    {
        gpa=g;
        physics=p;
        chemistry=c;
        math=m;
    }
    int totalmarks()
    {
        float total;
        string apply;
        total=physics+chemistry+math;
        cout<<"total= "<<total<<endl<<"gpa= "<<gpa<<endl;
        if (gpa<4.95||total<500)
        {
            cout<<"Sorry!You are not eligible to apply..."<<endl;
            return 5;

        }
        else
        {
            cout<<"You can apply..."<<endl<<"Do you want to apply now?\nEnter \"yes\" or \"no\""<<endl;
            cin>>apply;
            if(apply=="yes")
                m=1;
            else
                m=0;
            return 0;
        }
    }
};

class student_details
{
    string name,district,id,fathers_name,mothers_name,mobile_number;
    int passing_year,ad_roll;
    float gpa;
public:

    getdetails(string n,string i,string d,string ft,string mt,float g,int p,string mob_num)
    {
        name=n;
        mobile_number=mob_num;
        district=d;
        id=i;
        fathers_name=ft;
        mothers_name=mt;
        gpa=g;
        ad_roll=random;
        random++;
        passing_year=p;
    }
    void showdetails();
    friend class final_messege;
    friend void updt(student_details s[]);
    friend void download_admit(final_messege f[],student_details s[]);
    friend void download_info(string iid,student_details s[],final_messege f[]);
};

void updt(student_details s1[])
{
    string nm,dst,idd,fathersname,mothersname;
    int passingyear;
    float Gpa;
    cout<<"Enter the valid information you want to update:"<<endl;
    cout<<"Name:";
    fflush(stdin);
    getline(cin,nm);
    fflush(stdin);
    s1[i].name=nm;
    cout<<"district:";
    fflush(stdin);
    getline(cin,dst);
    s1[i].district=dst;
    cout<<"Id:";
    fflush(stdin);
    getline(cin,idd);
    s1[i].id=idd;
    cout<<"fathers_name:";
    fflush(stdin);
    getline(cin,fathersname);
    fflush(stdin);
    s1[i].fathers_name=fathersname;
    cout<<"mothers_name:";
    getline(cin,mothersname);
    s1[i].mothers_name=mothersname;
    cout<<"passing_year:";
    cin>>passingyear;
    s1[i].passing_year=passingyear;
    cout<<"HSC's GPA:";
    cin>>Gpa;
    s1[i].gpa=Gpa;
    cout<<endl;
    cout<<"Information succesfully updated..."<<endl;
}
void student_details::showdetails()
{
    string crct;
    cout<<"\n\nCheck if it's correct.Enter 'yes' or 'no':\n"<<endl;
    cout<<"name: "<<name<<endl<<"Fathers name: "<<fathers_name<<endl;
    cout<<"Mothers name: "<<mothers_name<<endl<<"id: "<<id<<endl;
    cout<<"Mobile number: "<<mobile_number<<endl<<"gpa: "<<gpa<<endl;
    cout<<"HSC passing year:"<<passing_year<<endl;

    cout<<"\n\nIf correct enter 'yes' ,else enter 'no'\n"<<endl;
    cin>>crct;
    if(crct=="yes")
        temp=1;
    else
    {
        temp=0;
    }
}

class payment_system
{
    int date,year,month;
    float money;
public:
    void getdata(int d,int m,int y,float mon)
    {
        date=d;
        year=y;
        month=m;
        money=mon;
    }
    void check()
    {
        cout<<"your apply date:";
        cout<<date<<"."<<month<<"."<<year<<endl;
        if(date<=30 && date>=1 && month!=7&& year!=2023 )
            cout<<"Sorry apply time is over.You can't apply."<<endl;
        else
        {
            if(money==1050)
            {
                flag=0;
                cout<<"Yes.you have successfully paymented"<<endl;
            }

            else
            {
                cout<<"not exact money paymented.Try again"<<endl;
                flag=1;
            }

        }
    }
};

class final_messege
{
    string time;
    string shift,center;
public:
    final_messege() {}
    final_messege(string shft,string cntr)
    {
        if(shft=="A" || shft=="a")
            time=tm1;
        if(shft=="B" || shft=="b")
            time=tm2;
        shift=shft;


        center=cntr;
    }
    void display_shedule(student_details *s)
    {
        cout<<"Your roll number is:"<<(s->ad_roll)<<endl;
        cout<<"Your  exam time:"<<time<<endl;
        cout<<"Your selected shift:"<<shift<<endl;
        cout<<"Your admission test will be held on 1st August,2023"<<endl;
        cout<<"Your selected center:"<<center<<endl;

    }
    friend void download_admit(final_messege f[],student_details s[]);
    friend void download_info(string iid,student_details s[],final_messege f[]);
};
void download_admit(final_messege f[],student_details s[])
{
    cout<<"\t\tADMIT CARD";
    cout<<endl<<endl<<endl;
    cout<<"Name         : "<<s[i].name<<endl;
    cout<<"Roll         : "<<s[i].ad_roll<<endl;
    cout<<"ID           : "<<s[i].id<<endl;
    cout<<"Father's name: "<<s[i].fathers_name<<endl;
    cout<<"Mother's name: "<<s[i].mothers_name<<endl;
    cout<<"Mobile       : "<<s[i].mobile_number<<endl;
    cout<<"center       : "<<f[i].center<<endl;
    cout<<"Shift        : "<<f[i].shift<<endl;
    cout<<"Time         : "<<f[i].time<<endl;
}
void download_info(string iid,student_details *s,final_messege *f)
{

    if(s->id==iid)
    {
        cout<<"Name         : "<<s->name<<endl;
        cout<<"Roll         : "<<s->ad_roll<<endl;
        cout<<"ID           : "<<s->id<<endl;
        cout<<"Father's name: "<<s->fathers_name<<endl;
        cout<<"Mother's name: "<<s->mothers_name<<endl;
        cout<<"Mobile       : "<<s->mobile_number<<endl;
        cout<<"center       : "<<f->center<<endl;
        cout<<"Shift        : "<<f->shift<<endl;
        cout<<"Time         : "<<f->time<<endl;
        dummy=1;


    }

}

int main()
{
    student_details sd[100];
    final_messege fm[100];
    cout<<"\t\t\t|| WELCOME TO ABC ENGINEERING COLLEGE,KHULNA ||"<<endl;
    cout<<"\t\t\t||          RUN AFTER EXCELLENCE             ||"<<endl;
    cout<<"\t\t\t_______________________________________________"<<endl;
    cout<<"\t\t\t_______________________________________________"<<endl<<endl<<endl;
    float gpa,pm,cm,mm;
main_menu:

    cout<<"\nWhat do you want?"<<endl;
    cout<<"1.Download information.\n2.Apply now.\n3.Exit"<<endl;
    cout<<"Enter your choice 1, 2 or 3:"<<endl;
    int choice;
    cin>>choice;
    if(choice==1)
    {
        cout<<"Enter your ID: ";
        string ID;
        cin>>ID;
        for(int j=0; j<loop_control+1; j++)
        {
            download_info(ID,&sd[j],&fm[j]);
        }
        if(dummy==0)
        {
            cout<<"______________________________"<<endl;
            cout<<"\nSorry,you have not applied yet.\n"<<endl;
            cout<<"________________________________"<<endl;
        }


        goto main_menu;
    }

    else if(choice==2)
    {

        cout<<"\nEnter your HSC's GPA:";

        cin>>gpa;


        cout<<"Enter physics_marks:";
        cin>>pm;
        cout<<"Enter chemistry_marks:";
        cin>>cm;
        cout<<"Enter math_marks:";
        cin>>mm;
        if(gpa>5.0 || gpa<1.0 || pm>200 || pm<0 || cm>200 || cm<0 || mm>200 || mm<0)
        {
            cout<<"You have given invalid data..."<<endl;
            goto main_menu;
        }
        applicability s1(gpa,pm,cm,mm);

        int a=s1.totalmarks();
        if(a)
            goto main_menu;
        if(m==0)
            goto main_menu;

        if(m)
        {
resubmit:
            string nam,dis,r,id,ft,mt,q,phone_num;
            float gpa;
            int p;
            cout<<"Enter name:";
            cin.ignore();
            getline(cin,nam);

            cout<<"Enter id:";



            getline(cin,id);
            cout<<"Enter your mobile number:";

            getline(cin,phone_num);

            cout<<"Enter district:";

            getline(cin,dis);
            cout<<"Enter fathers_name:";

            getline(cin,ft);
            cout<<"Enter mothers_name:";

            getline(cin,mt);
            cout<<"Enter HSC's GPA:";
            cin>>gpa;
            cout<<"Enter your HSC passing year:";
            cin>>p;



            sd[i].getdetails(nam,id,dis,ft,mt,gpa,p,phone_num);
            sd[i].showdetails();
            if(temp)
            {
                payment_system p1;
                int day,year,month;
                float money;
                cout<<"_________________________________________________________________"<<endl;
                cout<<"Now complete your payment and others"<<endl;
                cout<<"Due date of application is from 1 july,2023 to 30 july,2023....."<<endl;
                cout<<"_________________________________________________________________"<<endl<<endl;
                cout<<"today's date:";
                cin>>day;
                cout<<"month:";
                cin>>month;
                cout<<"year:";
                cin>>year;
                cout<<"payment tk.1050:";
                cin>>money;
                p1.getdata(day,month,year,money);
                p1.check();
                if(flag==1)
                {

                    goto main_menu;
                }

            }
            else
            {
                cout<<"\nResubmit:\n"<<endl;
                goto resubmit;
            }
        }
        string update;
        cout<<"\n_________________________________________________"<<endl;
        cout<<"Do you want to update your details.'yes' or 'no'?"<<endl;
        cout<<"_________________________________________________"<<endl<<endl;
        cin>>update;
        if(update=="yes")
        {
            updt(&sd[i]);
        }
        string shift,center;
        cout<<"Enter shift(A or B):";
        cin>>shift;
        cout<<"Enter  center from(KUET,RUET,CUET):";
        cin>>center;
        cout<<endl;

        fm[i]=final_messege(shift,center);
        fm[i].display_shedule(&sd[i]);
        cout<<"OK ,you have successfully registered.Best of luck for your admission test."<<endl;
        cout<<"Do you want to download your admit card? \nenter \"yes\" or \"no\":"<<endl;
        cout<<"________________________________________"<<endl;
        string admit;
        cin>>admit;
        if(admit=="yes" || admit=="YES")
            download_admit(&fm[i],&sd[i]);

        cout<<endl;

        cout<<"\n____________________________________________________"<<endl;
        cout<<"For any kind of queries please contact with us ..."<<endl;
        cout<<"ABC Engineering College,Khulna\nPhone:059278"<<endl;
        i++;
        loop_control=i;
    }
    else if(choice==3)
    {
        cout<<"You have successfully exited..."<<endl;
        return 0;
    }
    goto main_menu;
    return 0;

}







