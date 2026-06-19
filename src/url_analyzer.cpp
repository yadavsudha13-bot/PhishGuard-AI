#include <iostream>
#include <cctype>
#include <algorithm>
#include <string>
using namespace std;
string toLowercase(string str)
{
    transform(str.begin(), str.end(), str.begin(), ::tolower);
    return str;
}
int countDots(string url)
{
    int dots = 0;
    for (char ch : url)
    {
        if (ch == '.')
        {
            dots++;
        }
    }
    return dots;
}
int countHyphens(string url)
{
    int hyphens = 0;
    for (char ch : url)
    {
        if (ch == '-')
        {
            hyphens++;
        }
    }
    return hyphens;
}
void printVerdict(int score)
{
    if (score < 30)
    {
        cout << "Verdict : Safe" << endl;
    }
    else if (score < 60)
    {
        cout << "Verdict : Suspicious" << endl;
    }
    else
    {
        cout << "Verdict : Dangerous" << endl;
    }
}
bool containsIPaddress(string url)
{
    int digits = 0;
    for (char ch : url)
    {
        if (isdigit(ch))
        {
            digits++;
        }
    }
    if (digits >= 4 && countDots(url) >= 3)
    {
        return true;
    }
    return false;
}
bool containsAtSymbol(string url)
{
    return url.find('@') != string::npos;
}
bool hasTooManyDots(int dots)
{
    return dots > 3;
}
bool hasLongURL(string url)
{
    return url.length() > 30;
}
bool usesHTTPS(string url)
{
    return url.find("https://") == 0;
}
bool hasSuspiciousTLD(string url)
{
    return url.find(".xyz") != string::npos ||
           url.find(".top") != string::npos ||
           url.find(".click") != string::npos;
}
string extractDomain(string url)
{
    size_t start = url.find("://");

    if(start != string::npos)
    {
        start += 3;
    }
    else
    {
        start = 0;
    }

    size_t end = url.find('/', start);

    if(end == string::npos)
    {
        return url.substr(start);
    }

    return url.substr(start, end - start);
}
bool containsBrandName(string domain)
{
    string brands[] = {
        "paypal",
        "google",
        "amazon",
        "microsoft",
        "facebook"
    };

    for(string brand : brands)
    {
        if(domain.find(brand) != string::npos)
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string url;

    cout << "Enter URL: ";
    getline(cin, url);

    cout << "You entered: " << url << endl;

    cout << "URL length: " << url.length() << endl;

    url = toLowercase(url);

    int dots = countDots(url);
    int hyphens = countHyphens(url);

    cout << "Dot: " << dots << endl;
    cout << "Hyphens: " << hyphens << endl;

    string keywords[] = {"login", "verify", "secure", "update", "banking", "account"};

    cout << "Keywords found: " << endl;

    int score = 0;

    if (hasLongURL(url))
    {
        score += 20;
    }
    score += hyphens * 10;

    for (string word : keywords)
    {
        if (url.find(word) != string::npos)
        {
            cout << word << " found" << endl;

            if (word == "login" || word == "verify")
            {
                score += 20;
            }
            else
            {
                score += 15;
            }
        }
    }
    if (containsIPaddress(url))
    {
        cout << "IP Address detected!" << endl;
        score += 30;
    }
    if (containsAtSymbol(url))
    {
        cout << "@ Symbol detected!" << endl;
        score += 25;
    }
    if (hasTooManyDots(dots))
    {
        cout << "Too many dots detected!" << endl;
        score += 15;
    }
    if (usesHTTPS(url))
    {
        cout << "HTTPS detected" << endl;
    }
    else
    {
        cout << "Not using HTTPS" << endl;
        score += 10;
    }
    if (hasSuspiciousTLD(url))
    {
        cout << "Suspicious TLD detected!" << endl;
        score += 20;
    }
    string domain = extractDomain(url);

    cout << "Domain: " << domain << endl;

if(containsBrandName(domain))
{
    cout << "Brand name detected in domain!" << endl;
    score += 25;
}

    score = min(score, 100);

    cout << "\nRisk Score: " << score << "/100" << endl;

    printVerdict(score);

    return 0;
}