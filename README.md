# PhishGuard-AI

A rule-based phishing URL detection tool developed in C++.

## Features

- URL Length Detection
- Hyphen Detection
- Dot Count Analysis
- Suspicious Keyword Detection
- Multiple Keyword Detection
- IP Address Detection
- @ Symbol Detection
- Too Many Dots Detection
- Too Many Digits Detection
- HTTPS Verification
- Suspicious TLD Detection
- Domain Extraction
- Brand Impersonation Detection
- URL Shortener Detection
- Suspicious File Extension Detection

## How It Works

The program analyzes URLs and assigns risk points based on suspicious characteristics.

Risk Levels:

- 0–29 : Safe
- 30–59 : Suspicious
- 60–100 : Dangerous

## Project Overview

PhishGuard-AI is a rule-based phishing URL detection tool built in C++.

The application analyzes URLs for common phishing indicators such as suspicious keywords, brand impersonation attempts, shortened URLs, suspicious file extensions, IP-based URLs, and unsafe top-level domains.

The tool calculates a risk score between 0 and 100 and classifies URLs as Safe, Suspicious, or Dangerous.

## Example Scan

Input:
http://download-secure-update.xyz/invoice.exe

Output:
secure found
update found
Not using HTTPS
Suspicious TLD detected!
Suspicious file extension detected!

Risk Score: 100/100
Verdict: Dangerous

## Future Improvements

- Machine Learning based URL classification
- Domain reputation analysis
- Real-time URL scanning
- Browser extension support
- Threat intelligence integration
- Detection of typosquatting attacks


## Author

Sudha Yadav
Cyber Security Engineering Student

