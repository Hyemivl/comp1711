"""
Introduction to Programming Coursework 1

@author: Neil Herath
"""


def valid_puzzle(puzzle: list) -> bool:
    length = len(puzzle[0])
    output = True
    for x in puzzle:
        if (len(x) != length):
            output = False
    if (len(puzzle[0]) <= 1):
        output = False
    return output


def similarity_grouping(data: list) -> list:
    temp = ' '
    templist = []
    output = []
    counter = 0
    if isinstance(data, list):
        while data != []:
            temp = data[0]
            while (counter < len(data)):
                if temp == data[counter]:
                    data.remove(temp)
                    templist.append(temp)
                    counter = counter - 1
                counter = counter + 1
            output.append(templist)
            counter = 0
            templist = []
    return output


def highest_count_items(data: str) -> list:
    listofcount = []
    dictionaryofcount = {}
    output = []
    if isinstance(data, str):
        strlist = (data.split(", "))
        for x in strlist:
            listofcount.append(strlist.count(x))
            dictionaryofcount[x] = strlist.count(x)
        highestcount = max(listofcount)
        for x, y in dictionaryofcount.items():
            if (y == highestcount):
                output.append([x, y])
    return output


def valid_char_in_string(popList: list, charSet: list) -> bool:
    output = True
    if not isinstance(charSet, list):
        return False
    for x in charSet:
        if (len(x) > 1) and isinstance(x, str):
            return False
    for x in popList:
        if not all(c in charSet for c in x):
            output = False
    return output


def total_price(unit: int) -> float:
    output = 0
    output = 5 * (unit // 6) + 1.25 * (unit % 6)
    if output >= 20:
        output = output * 0.9
    return output


if __name__ == "__main__":
    # sample test for task 1.1
    puzzle1 = ['RUNAROUNDDL', 'EDCITOAHCYV', 'ZYUWSWEDZYA', 'AKOTCONVOYV',
               'LSBOSEVRUCI', 'BOBLLCGLPBD', 'LKTEENAGEDL', 'ISTREWZLCGY',
               'AURAPLEBAYG', 'RDATYTBIWRA', 'TEYEMROFINU']

    puzzle2 = ['NAROUNDDL', 'EDCIT', 'UWSWEDZYA', 'OTCONVOYV',
               'BOSEVRUCI', 'BLLCGLPBD', 'TEENAGEDL', 'TREWZLCGY',
               'RAPLEBAYG', 'ATYTBIWRA', 'YEMROFINU']

    puzzle3 = ['RUNAROU', ['EDCITOA'], ('ZYUWSWE'), 'AKOTCYV',
               'LSBOSEI', 'BOBLLCG', 'LKTEENA', 'ISTREWY',
               'AURAPLE', 'RDATYTB', 'TEYEMRO']
    puzzle4 = 'roundandround'
    print(valid_puzzle(puzzle1))
    print(valid_puzzle(puzzle2))
    print(valid_puzzle(puzzle3))
    print(valid_puzzle(puzzle4))

    # sample test for task 1.2
    data1 = [2, 1, 2, 1]
    data2 = [5, 4, 5, 5, 4, 3]
    data3 = [1, 2, 1, 3, 'a', 'b', "a",  'c']
    print(similarity_grouping(data1))
    print(similarity_grouping(data2))
    print(similarity_grouping(data3))

    # sample test for task 1.3
    data4 = ("3, 13, 7, 9, 3, 3, 5, 7, 12, 13, 11, 13, 8, 7, 5, 14, 15, 3, 9, "
             "7, 5, 9, 14, 3, 8, 2, 5, 5, 8, 14, 11, 11, 12, 8, 5, 3, 3, 10, "
             "3, 10, 7, 7, 10, 10, 2, 7, 4, 8, 1, 5")
    data5 = ("British Gas, British Gas, Ovo, Igloo, Igloo, Octopus, Bulb, "
             "Shell, E.ON, Npower, British Gas, Octopus, Igloo, Npower, Igloo, "
             "Shell, Scottish Power, Bulb, EDF, Bulb, EDF, Bulb, "
             "Scottish Power, Octopus, Scottish Power, Octopus, Octopus, EDF, "
             "Ovo, Shell, Octopus, E.ON, British Gas, Bulb, Npower, Shell, "
             "Scottish Power, Npower, Scottish Power, Npower")
    data6 = ("aac, ctt, gat, ccc, gcc, ctg, gtc, tcg, ccg, cca, ata, cca, "
             "tat, ata, cac, gcg, cca, gta, gtg, gac, taa, ata, gtc, aat, gct, "
             "gta, ggc, tgc, tca, ctt, tgt, ata, acc, tgc, gac, cgc, atc, cgt, "
             "tac, agg, ctt, cgc, cgc, tgg, gcg, tgg, taa, cta, aaa, tgc, cgt, "
             "tgc, gac, tta, aag, taa, act, cca, tac, agg, cgc, gtg, cca, gcg, "
             "gtt, gag, tca, aca, tct, gta, ata, ctt, gat, tcg, tcg, cac, cgt, "
             "tac, caa, aac, ctg, tgt, aag, ttc, ccc, tcc, ctc, cct, aga, gtt, "
             "tga, gaa, cct, ctc, tct, ggt, gcc, tct, ccc, agt, caa, gac, ccc, "
             "cgc")
    print(highest_count_items(data4))
    print(highest_count_items(data5))
    print(highest_count_items(data6))

    # sample test for task 1.4
    popList1 = ['00000', '00001', '00010', '00011', '00100']
    popList2 = ['aac', 'ctt', 'gat', 'ccc', 'gcc', 'ctg', 'gtc', 'tcg',
                'ccg', 'cca', 'ata']
    popList3 = ['aac', 'ctt', 'gat', 'ccc', 'gcc', 'ctg', 'gtc']
    charSet1 = ['0', '1']
    charSet2 = ['a', 'c', 't', 'g']
    charSet3 = ['a', 'c']
    charSet4 = '01'
    print(valid_char_in_string(popList1, charSet1))
    print(valid_char_in_string(popList2, charSet2))
    print(valid_char_in_string(popList3, charSet3))
    print(valid_char_in_string(popList1, charSet4))

    # sample test for task 1.5
    print(total_price(3))
    print(total_price(12))
    print(total_price(15))
    print(total_price(26))
