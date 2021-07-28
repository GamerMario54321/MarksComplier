#include <iostream>
#include <fstream>
#include <climits>
using namespace std;

int main()
{
    //The variables
    int students, i, o, sum, gradeA[o], subject;
    double average[o];
    char again = 'y', fileans;
    string name, subjectname[o];

    //while for again input
    while(again == 'y' || again == 'Y')
    {
        //Prompting the user to enter the number of students
        cout << string(50, '\n');
        cout << "Enter no. of students : ";
        cin >> students;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You can only enter numbers.\n" << endl;
            cout << "Enter no. of students : ";
            cin >> students;
        }

        //Prompting the user to enter the number of subject
        cout << "Enter no. of subjects : ";
        cin >> subject;
        while (cin.fail())
        {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << "You can only enter numbers.\n" << endl;
            cout << "Enter no. of subjects : ";
            cin >> subject;
        }

        //Prompting the user to enter subject name/code
        for(o = 1; o <= subject; o++)
        {
            cout << "Enter name/code for subject " << o << " : ";
            cin >> subjectname[o];
        }

        //Declaring an array for marks
        int marks[students][subject];
        /*


        LINE BREAK


        */
        //Prompting the user to enter the marks for each students and subject
        for(o = 1; o <= subject; o++)
        {
            cout << string(50, '\n');
            cout << "Entering for " << subjectname[o] << "\n" << endl;
            for(i = 1; i <= students; i++)
            {
                cout << "Enter marks of student " << i << " : ";
                cin >> marks[i][o];
                while (cin.fail())
                {
                    cin.clear();
                    cin.ignore(INT_MAX, '\n');
                    cout << "You can only enter numbers.\n" << endl;
                    cout << "Enter marks of student " << i << " : ";
                    cin >> marks[i][o];
                }
            }
            cout << string(50, '\n');
        }
        /*


        LINE BREAK


        */
        for(o = 1; o <= subject; o++)
        {
            //Displaying the marks for each student for reference
            cout << subjectname[o] << endl;
            for(i = 1; i <= students; i++)
            {
                cout << "student " << i << ": " << marks[i][o] << endl;
            }
            cout << endl;
            /*


            LINE BREAK


            */
            //To find the average from all the marks
            sum = 0.0;
            for(i = 1; i <= students; i++)
            {
                sum = sum + marks[i][o];
            }
            average[o] = sum / (students*1.0);
            cout << "The average mark for " << subjectname[o] << " : " << average[o] << endl;
            /*


            LINE BREAK


            */
            //To find the no. of Grade A from the students marks
            gradeA[o]=0;
            for(i = 1; i <= students; i++)
            {
                if(marks[i][o] >= 80)
                gradeA[o]++;
            }
            cout << "The no. of Grade A achieved for " << subjectname[o] << " : " << gradeA[o] << endl << endl;
            system("pause");
            cout << string(50, '\n');
        }
        /*


        LINE BREAK


        */
        //Option if they want a Txt file created
        cout << "\nDo you want to create a Txt file? (y/n) :";
        cin >> fileans;

        if(fileans == 'y' || fileans == 'Y')
        {
            cout << "Please name this file : ";
            cin >> name;
            name += string(".txt");
            ofstream MyFile(name);
            MyFile << "---------------------" << endl;
            for(o = 1; o <= subject; o++)
            {
                MyFile << subjectname[o] << endl << endl;
                for(i = 1; i <= students; i++)
                {
                    MyFile << "Student " << i << ": " << marks[i][o] << endl;
                }
                MyFile << "\nAverage : " << average[o] << endl;
                MyFile << "No. of As : " << gradeA[o] << endl;
                MyFile << "---------------------" << endl;
            }
            MyFile.close();
            cout << "\nTxt file was created..." << endl;
            cout << "File can be found in your exe folder" << endl;
        }
        else
        {
            cout << "File not created, everything entered will be lost" << endl;
        }
        /*


        LINE BREAK


        */
        //Prompting the user if he would like to use the program again
        cout << "\nWould you like to use the program again? (y/n) : ";
        cin >> again;
    }

    //Simple Thank you message
    cout << string(50, '\n');
    cout << "======================" << endl;
    cout << "      Thank You!      " << endl;
    cout << "======================" << endl << endl;
    system("pause");

    return 0;
}
