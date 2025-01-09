# Stock Market Simulation
This program was created only by myself in Visual Studio 2022 using C++20 and Python 3.11 with matplotlib and pandas.
Game at the end of turn adds to CSV file new random assets values. Using python you can plot chart witch stock values of choosed asset. 
Used are smart pointers, dynamic pointer casts, lambda functions, templates, iterators, classes, polimorphism, virtual functions, constructors, overloaded operators, file operations, exceptions handling, variables from STL like map, list, vestor etc. and many many more.

C++

![image](https://github.com/user-attachments/assets/9397cf1b-1769-4b16-bd1c-cd4588caf74a)

Python

![image](https://github.com/user-attachments/assets/79578c8b-f1a2-4541-822d-0aead8fe4094)

## Game Description

This is a banking simulation game where players manage their savings and investment accounts. The goal of the game is to accumulate the highest value of assets and money in their portfolio. Players have the ability to buy various types of assets, such as cryptocurrencies, currencies, real estate, and stocks. The game progresses in turns, and players can make decisions at each stage to increase the value of their investments. 
Course of assets are changed randomply in every round so you must be carefull. Good luck!

## Account Types:

### 1. **Savings Account**:
- Focuses on safely accumulating money without risk.
- Players can make deposits or build gold and earn interest on savings.
- The savings grow over time as each turn simulates the passage of time for deposit accumulation.

### 2. **Investment Account**:
- Allows players to make riskier investments, such as:
  - **Buying cryptocurrencies**
  - **Buying currencies**
  - **Buying real estate**
  - **Buying stocks**
- Each of these investments carries varying levels of risk and potential returns.

## Game Rules:
- The game is **turn-based**. Each turn represents a period during which the investments and deposits are updated.
- At the end of each turn, the account balances and asset values are updated.
- Players can interact with various features, such as buying assets, calculating account worth, and generating reports.
- **Objective**: The winner is the player with the highest total value of assets and money in their portfolio after a set number of turns or upon completion of the game.

## System Requirements:
- **Python 3.x** installed.
- Required Python libraries:
  - `matplotlib` (for plotting graphs)
  - `pandas` (for handling data in CSV files)

## Installation:

### 1. **Install Python 3.x**:
   - Download and install Python 3.x from [here](https://www.python.org/downloads/).

### 2. **Install the required Python libraries**:
   - Open your terminal or command prompt and run the following command:
     ```bash
     pip install matplotlib pandas
     ```

### 3. **Running the Game**:
   - open ProjectOne.exe in Stock_market_simulation_C --> ProjectOne --> x64 --> Release --> ProjectOne.exe

## Features

### 1. **Savings Account**:
   - **Investing in gold**
   - **Depositing money** – adding funds to the savings account.

### 2. **Investment Account**:
   - **Buying assets**:
     - **Cryptocurrencies**: invest in popular cryptocurrencies.
     - **Currencies**: purchase different currencies.
     - **Real Estate**: buy and sell properties.
     - **Stocks**: invest in company stocks.

### 3. **Turn Simulation**:
   - **Deposit simulation** – at the end of each turn, deposit values are updated, and the savings account balance increases based on the time elapsed.
   - **Assets value simulation** – at the end of each turn, assets are changed.

### 4. **Graphs (Python)**:
   - The game allows generating graphs from data stored in CSV files that are updated during the game.
   - The Python script reads the CSV file and generates graphs showing asset and account value changes.
   - To display the graphs, you must install Python and the required libraries:
     - `matplotlib` for graph plotting.
     - `pandas` for handling CSV files.

## Future Development Plan
The game will be expanded with additional features in the future, such as:
- Better simulation of assets changed based on API or using advanced mathematics.
- New types of assets (e.g., bonds, startups).
- Risk options in investments.
- Advanced investment strategies.

## Summary
The game offers a rich banking simulation where players manage finances, investments, and assets across various sectors. Players make decisions at every turn, and the goal is to maximize the value of their assets. The game is turn-based, and the financial outcomes can be visualized using Python-generated graphs.
