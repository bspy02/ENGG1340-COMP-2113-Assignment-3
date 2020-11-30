#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

struct Page
{
    int id;
    string path;
    int counter;

    Page(int id, string path)
    {
        this->id = id;
        this->path = path;
        counter = 0;
    };
};

// This function can facilitate sorting
bool operator<(const Page &a, const Page &b)
{
    if (a.id < b.id)
        return true;
    if (a.id > b.id)
        return false;
    return (a.path > b.path);
}

vector<Page> pages;

struct User
{
    int id;
    vector<string> visits;

    User(int id)
    {
        this->id = id;
    };

    int size() const
    {
        return visits.size();
    };

    void print_visits()
    {
        sort(visits.begin(), visits.end());
        vector<string>::iterator iter;

        for (iter = visits.begin(); iter != visits.end(); iter++)
        {
            cout << "- " << *iter << endl;
        }
    }
};

vector<User> users;

// Please implement the following function to facilitate the sorting of users
bool operator<(const User &a, const User &b)
{
    if (a.size() < b.size())
        return true;
    if (a.size() > b.size())
        return false;
    return (a.id > b.id);
}

// Please implement the following function
bool cmp_page_count(const Page &a, const Page &b)
{
    if (a.counter > b.counter)
        return true;
    if (a.counter < b.counter)
        return false;
    return (a.path < b.path);
}

int main()
{

    string type;
    while (cin >> type)
    {
        if (type == "USER")
        {
            int user_id;
            cin >> user_id;
            User u(user_id);
            users.push_back(u);
        }

        else if (type == "PAGE")
        {
            int page_id;
            string page_path;
            cin >> page_id;
            cin >> page_path;
            Page p(page_id, page_path);
            pages.push_back(p);
        }

        else if (type == "VISIT")
        {
            int page_id;
            cin >> page_id;

            for (int i = 0; i < pages.size(); i++)
            {
                if (pages[i].id == page_id)
                {
                    pages[i].counter++;
                    users.back().visits.push_back(pages[i].path);
                }
            }
        }
    }
    sort(pages.begin(), pages.end(), cmp_page_count);
    cout << "*** 5 most popular pages ***" << endl;
    int number = 5;
    int n = pages.size();
    for (int i = 0; i != number; i++)
    {
        cout << pages[i].counter << ":" << pages[i].path << endl;
    }

    sort(users.begin(), users.end());
    cout << "*** 5 most active users ***" << endl;
    n = users.size();
    for (int i = n - 1; i != n - number - 1; i--)
    {
        cout << users[i].size() << ":" << users[i].id << endl;
        users[i].print_visits();
    }
    return 0;
}