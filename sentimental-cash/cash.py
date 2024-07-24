from cs50 import get_float


# main function
def main():
    dollars = 0
    # Checking if dollars are less than 0
    while dollars <= 0:
        dollars = get_float("Change Owed: ")
        # Converting dollars to cents
        cents = dollars * 100
        # Calculate the number of quarters to give the customer
        quarters = calculate_quarters(cents)
        cents = cents - quarters * 25
        # Calculate the number of dimes to give the customer
        dimes = calculate_dimes(cents)
        cents = cents - dimes * 10
        # Calculate the number of nickels to give the customer
        nickels = calculate_nickels(cents)
        cents = cents - nickels * 5
        # Calculate the number of pennies to give the customer
        pennies = calculate_pennies(cents)
        cents = cents - pennies * 1
        # Sum coins to be returned to customer
        coins = quarters + dimes + nickels + pennies
        # Print total number of coins to give the customer
        print(coins)


# function to get number of quarters
def calculate_quarters(cents):
    quarters = cents // 25
    return quarters


# function to get number of dimes
def calculate_dimes(cents):
    dimes = cents // 10
    return dimes


# function to get number of nickels
def calculate_nickels(cents):
    nickels = cents // 5
    return nickels


# function to get number of pennies
def calculate_pennies(cents):
    pennies = cents // 1
    return pennies


main()
