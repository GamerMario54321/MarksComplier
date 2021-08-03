#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int students(int stu);
int subjects(int sub);
double calculateaverage(double total, int divider);

int main()
{
    //Variables
    int num_student, num_subject, o, i, ans1;
    double sum;
    char fileans, again = 'y';
    string name, txtfile;

    while(again == 'y' || again == 'Y') //While loop should program would run again
    {
        //Prompting the user for editing or creating
        cout << string(50, '\n');
        cout << "What would you like to do?\n" << endl;
        cout << "1) Create new folder\n2) Read existing txt file\n" << endl;
        cout << "Enter here : ";
        cin >> ans1;
        /*


        LINE BREAK


        */
        if(ans1 == 1)
        {
            //Prompting the user to enter the number of students
            num_student = students(num_student);

            //Prompting the user to enter the number of subjects
            num_subject = subjects(num_subject);

            //Declaring arrays
            int marks[num_student][num_subject], gradeA[1000];
            double average[1000];
            string subjectname[1000];
            /*


            LINE BREAK


            */
            //Prompting the user to enter subject names
            for(o = 1; o <= num_subject; o++)
            {
                cout << string(50, '\n');
                cout << "Enter subject name of subject " << o << " : ";
                cin >> subjectname[o];
            }
            /*


            LINE BREAK


            */
            //Prompting the user to enter the marks for the students
            for(o = 1; o <= num_subject; o++)
            {
                cout << string(50, '\n');
                cout << "Entering for " << subjectname[o] << endl << endl;
                for(i = 1; i <= num_student; i++)
                {
                    cout << "Enter marks for student " << i << " : ";
                    cin >> marks[i][o];
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "You can only enter numbers.\n" << endl;
                        cout << "Enter marks for student " << i << " : ";
                        cin >> marks[i][o];
                    }
                }
            }
            /*


            LINE BREAK


            */
            //Displaying the marks, average, and gradeA of students for subjects
            for(o = 1; o <= num_subject; o++)
            {
                sum = 0.0;
                gradeA[o] = 0;
                cout << string(50, '\n');
                cout << subjectname[o] << endl << endl;
                for(i = 1; i <= num_student; i++)
                {
                    cout << "Student " << i << " : " << marks[i][o] << endl;
                    while (cin.fail())
                    {
                        cin.clear();
                        cin.ignore(INT_MAX, '\n');
                        cout << "You can only enter numbers.\n" << endl;
                        cout << "Enter marks of student " << i << " : ";
                        cin >> marks[i][o];
                    }
                    sum += marks[i][o];
                    if(marks[i][o] >= 80)
                        gradeA[o]++;
                }
                cout << endl;
                average[o] = calculateaverage(sum, num_student);
                cout << "No. of As : " << gradeA[o] << endl << endl;
                system("pause");
            }
            /*


            LINE BREAK


            */
            //Option if they want a Txt file created
            cout << string(50, '\n');
            cout << "\nDo you want to create a Txt file? (y/n) :";
            cin >> fileans;
            if(fileans == 'y' || fileans == 'Y')
            {
                cout << "Please name this file : ";
                cin >> name;
                name += string(".txt");
                ofstream MyFile(name);
                MyFile << "---------------------" << endl;
                        for(o = 1; o <= num_subject; o++)
                {
                    MyFile << subjectname[o] << endl << endl;
                    for(i = 1; i <= num_student; i++)
                    {
                        MyFile << "Student " << i << ": " << marks[i][o] << endl;
                    }
                    MyFile << "\nAverage : " << average[o] << endl;
                    MyFile << "No. of As : " << gradeA[o] << endl;
                    MyFile << "---------------------" << endl;
                }
                MyFile.close();
                cout << string(50, '\n');
                cout << "\nTxt file was created..." << endl;
                cout << "File can be found in your exe folder" << endl;
            }
            else
            {
                cout << "File not created, everything entered will be lost" << endl;
            }
            //Prompting the user if he would like to use the program again
            cout << "\nWould you like to use the program again? (y/n) : ";
            cin >> again;
        }
        /*




        LINE BREAK




        */
        else if(ans1 == 2)
        {
            cout << string(50, '\n');
            cout << "Enter name of file : ";
            cin >> name;
            name += string(".txt");
            ifstream MyReadFile(name);
            cout << string(50, '\n');

            //If the file does not exist
            if(MyReadFile.fail())
            {
                cout << "File does not exist" << endl;
            }

            //If the file exist
            else
            {
            cout << "Opening " << name << endl;
            }


            while (getline (MyReadFile, txtfile))
            {
                if(txtfile == "---------------------")
                {
                    cout << endl;
                    system("pause");
                    cout << string(50, '\n');
                }
                else
                    cout << txtfile << endl;
            }
            MyReadFile.close();
            //Prompting the user if he would like to use the program again
            cout << "\nWould you like to use the program again? (y/n) : ";
            cin >> again;
        }
        /*




        LINE BREAK




        */
        else
        {
            cout << string(50, '\n');
            cout << "Wrong input detected. Please only enter correct values" << endl << endl;
            system("pause");
        }
    }

    //Simple Thank you message
    cout << string(50, '\n');
    cout << "======================" << endl;
    cout << "      Thank You!      " << endl;
    cout << "======================" << endl << endl;
    system("pause");
}

int students(int stu)
{
    cout << string(50, '\n');
    cout << "Enter no. of students : ";
    cin >> stu;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers.\n" << endl;
        cout << "Enter no. of students : ";
        cin >> stu;
    }
    return stu;
}

int subjects(int sub)
{
    cout << "Enter no. of subjects : ";
    cin >> sub;
    while (cin.fail())
    {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << "You can only enter numbers.\n" << endl;
        cout << "Enter no. of subjects : ";
        cin >> sub;
    }
    return sub;
}

double calculateaverage(double total, int divider)
{
    double average;
    average = (total*1.0)/(divider*1.0);
    cout << "Average : " << average << endl;
    return average;
}
