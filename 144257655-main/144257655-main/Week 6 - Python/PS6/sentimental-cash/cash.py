# TODO
from cs50 import get_float

change = -1
while change < 0:
    change = get_float("Change owed: ")

total_coins = 0

while change != 0.0:
    if change >= 0.25:
        change -= 0.25
        change = round(change, 2)
        total_coins += 1

    elif change >= 0.10:
        change -= 0.10
        change = round(change, 2)
        total_coins += 1

    elif change >= 0.05:
        change -= 0.05
        change = round(change, 2)
        total_coins += 1

    elif change >= 0.01:
        change -= 0.01
        change = round(change, 2)
        total_coins += 1


print(total_coins)
