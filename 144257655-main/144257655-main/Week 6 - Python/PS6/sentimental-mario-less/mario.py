# TODO
from cs50 import get_int


def main():
    pyramid = get_height()
    draw(pyramid)


def get_height():
    while True:
        height = get_int("Height: ")
        if height > 0 and height < 9:
            return height


def draw(input):
    width = input - 1
    blocks = 1

    for y in range(input):
        for x in range(width):
            print(" ", end="")

        for block in range(blocks):
            print("#", end="")

        print("")

        width -= 1
        blocks += 1


if __name__ == "__main__":
    main()
