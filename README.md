# C++ Banking System with Secure Authentication and Communication

## Project Overview
This robust C++ banking system is engineered to streamline banking operations, focusing on robust security measures, comprehensive user management, detailed client services, advanced transaction processing, and internal communication functionalities. It's a fully-fledged solution for a banking environment, equipped to handle a myriad of currencies.

![Project Overview Image](https://github.com/Alazaabat/BankSystem/assets/129705686/f4149828-bf55-4720-b485-568367c87767)

## Key Features

### Security and Authentication
- **Secure Login**: Implements a multi-attempt login system that locks users out after consecutive failed attempts to prevent unauthorized access.
- **Password Encryption**: Utilizes encryption for password storage, with decryption at the point of login, to safeguard user credentials.
- **Login Tracking**: Maintains meticulous logs of user login attempts, complete with timestamps for enhanced security oversight.

### Client Management
- **Client Profiles**: Facilitates the addition, updating, and deletion of client profiles, each identified by a unique account number and linked with extensive personal and financial details.
- **Balance Management**: Empowers administrators to monitor and manage client account balances, supporting a variety of transaction types.

### Transaction Handling
- **Financial Operations**: Enables deposits, withdrawals, and inter-account transfers with ease.
- **Transaction Logging**: Keeps an exhaustive record of all transactions for accountability and reconciliation purposes.

### User Management
- **Administrative Oversight**: Provides administrators with the tools to control user access, including the ability to add, update, or remove user accounts.
- **Permission Assignment**: Supports the assignment of permission levels to differentiate roles and access within the banking system.

### Communication System
- **Internal Email Service**: Allows for sending and receiving of emails within the system, negating the need for external email services and enhancing privacy.
- **Mailbox Management**: Offers the capability to manage and clear email boxes with the required password confirmation for actions, ensuring user authenticity.
- **Email Activity Log**: Captures all email activities, providing a complete log of sent and received emails along with pertinent details.

### Currency Exchange Module
- **Extensive Currency Listings**: Maintains a detailed list of global currencies for transactional purposes.
- **Real-Time Conversion**: Features a currency conversion tool that uses up-to-date exchange rates.
- **Currency Updates**: Admins can search for and update currency values to keep up with the fluctuating foreign exchange market.

### Data Persistence
- **File-Based Storage**: Reliably stores all data, including user profiles, client information, transactions, and emails in files, ensuring continuity and integrity of data.

## Documentation

### User Guide
- **Getting Started**: You have to log in first with User: Admin -> Password: 1234. This is a SuperUser that can add any user with any permission and delete any user.

#### Client Operations
- **Show Client List**: Navigate to 'Show Clients' from the main menu. You will get a table with information on all clients.
- **Adding a New Client**: Navigate to 'Add New Client' from the main menu. Enter the client's personal information as prompted.
- **Updating Client Information**: Select 'Update Client Info' from the main menu. Input the client's account number and update the necessary fields.
- **Deleting a Client**: Choose 'Delete Client' from the main menu. Enter the client's account number that you wish to delete and confirm the action.
- **Find a Client**: Choose 'Find Client' from the main menu. Enter the client's account number to get all info on this client.

#### Transaction Operations
- **Making a Deposit**: Select 'Deposit' from the Transactions menu. Enter the client's account number and the amount to deposit.
- **Withdrawing Funds**: Choose 'Withdraw' from the Transactions menu. Input the account number and the amount to withdraw.
- **Transferring Funds**: Go to 'Transfer' in the Transactions menu. Enter the source and destination account numbers and the transfer amount.

#### Communication
- **Sending Emails**: Access 'Send Email' from the Communication menu. Enter the recipient's username, subject, and message body.
- **Receiving Emails**: Emails received will appear in your 'Received Mailbox'. Open an email to read the content.
- **Managing Emails**: To clear your mailbox, select 'Clear Mailbox' and enter your password for confirmation.

#### Troubleshooting
- **Login Issues**: If you cannot log in, check your username and password and try again.
- **Transaction Errors**: Ensure the client's account number and transaction details are correct.
- **System Performance**: If the system is running slowly or not responding, try restarting the software.

#### FAQs
- **How do I reset my password?**: Password resets can be done by going to Manage Users using SuperUser (Admin), then Update User and change the password of the user you want to change.
- **Can I open multiple accounts for the same client?**: Yes, clients can have multiple accounts, each with a unique account number.
- **Is there a transaction limit?**: There is no transaction limit unless you are trying to withdraw an amount higher than your account balance.

### Screenshots and Usage
The repository includes screenshots that illustrate various features and modules of the system:

#### Authentication Process
![Authentication Process](https://github.com/Alazaabat/BankSystem/assets/129705686/c92ee120-c69e-430f-b83e-9275c0c7a1fa)

#### Client Information Management
![Client Information Management](https://github.com/Alazaabat/BankSystem/assets/129705686/8e139c17-1388-4410-ada9-9b5a20ddcfc5)

#### Transactional Processes
![Transactional Processes](https://github.com/Alazaabat/BankSystem/assets/129705686/35992e31-aff5-4d85-8cf4-00215fc74af9)

#### Communication Features
##### Sending Email to Houssam
![Sending Email](https://github.com/Alazaabat/BankSystem/assets/129705686/23639f94-e71b-458b-9efd-7049a370ee7e)
##### Admin Sent Mailbox
![Admin Sent Mailbox](https://github.com/Alazaabat/BankSystem/assets/129705686/0ad2857a-1da1-4141-8e1c-beaedb7d3d9e)
##### Houssam Received Mailbox
![Houssam Received Mailbox](https://github.com/Alazaabat/BankSystem/assets/129705686/284cffd2-1ea5-4654-97b2-a9c5d01ae1c2)

## Contributions
We welcome contributions that aim to enhance the system's functionalities or introduce new features. Please fork the repository and follow the provided guidelines for submitting pull requests.
