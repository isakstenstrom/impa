import math

while True:
    dice = input()
    split_dice = dice.split("D")
    number_of_dice = int(split_dice[0])
    dice_number = int(split_dice[1])
    if number_of_dice == 0 and dice_number == 0:
        break
    segment_len = math.ceil(math.log2(dice_number))
    if segment_len == 0:
        segment_len = 1

    sequence = input()
    chunks = [sequence[i:i+segment_len] for i in range(0, len(sequence), segment_len)]
    sum = 0
    used_all_dice = False
    for chunk in chunks:
        if len(chunk) != segment_len:
            break
        subsum = 0
        lettervalue = 1
        for letter in reversed(chunk):
            if letter == 'T':
                subsum += lettervalue
            lettervalue = lettervalue *2
        if subsum < dice_number:
            sum += subsum +1
            number_of_dice -= 1
            if number_of_dice == 0:
                used_all_dice = True
                break
    if not used_all_dice or sum == 0:
        print(-1)
    else:
        print(sum)