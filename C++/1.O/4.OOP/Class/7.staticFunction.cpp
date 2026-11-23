#include <iostream>
#include <string>
using namespace std;

class Printer
{
    int nPages_;
    static int nTrayPages_;
    static int nJobs_;

public:
    // Constructor
    Printer(int nP) : nPages_(nP)
    {
        ++nJobs_;
        cout << "Constructor || Printing " << nP << " pages" << endl;
        nTrayPages_ = nTrayPages_ - nP;
    }

    // Destructor
    ~Printer() { --nJobs_; }

    static int getJobs() { return nJobs_; }
    static int checkPages() { return nTrayPages_; }
    static void loadPages(int nP) { nTrayPages_ += nP; }
};

int Printer::nTrayPages_ = 500;
int Printer::nJobs_ = 0;

int main()
{
    cout << "Jobs= " << Printer::getJobs() << endl; // Jobs= 0

    Printer job1(10);
    cout << "Jobs= " << Printer::getJobs() << endl;
    cout << "Pages in Tray= " << Printer::checkPages() << endl;

    // Constructor || Printing 10 pages
    // Jobs= 1
    // Pages in Tray= 490

    {
        Printer job1(30), job2(40); // Different job1 in block scope
        cout << "Jobs= " << Printer::getJobs() << endl;
        cout << "Pages in Tray= " << Printer::checkPages() << endl;

        Printer::loadPages(100);

        // Constructor || Printing 30 pages
        // Constructor || Printing 40 pages
        // Jobs= 3
        // Pages in Tray= 420
    }

    cout << "Jobs= " << Printer::getJobs() << endl;
    cout << "Pages in Tray= " << Printer::checkPages() << endl;

    // Jobs= 1    --> scope ended - jobs got destructed
    // Pages in Tray= 520

    return 0;
}
