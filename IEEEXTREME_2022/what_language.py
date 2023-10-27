# a simple parser for python. use get_number() and get_word() to read
def parser():
    while 1:
        data = list(input().split(' '))
        for number in data:
            if len(number) > 0:
                yield(number)   

input_parser = parser()

def get_word():
    global input_parser
    return next(input_parser)

def get_number():
    data = get_word()
    try:
        return int(data)
    except ValueError:
        return float(data)

def remove_desc(ID):
    global removed
    global removed_char
    if nodes[ID][1] in removed_char:
        return 

    if nodes[ID][0] == 0:
        removed.append(nodes[ID][1])
    else:
        removed_char.append(nodes[ID][1])
        remove_desc(nodes[ID][2])
        remove_desc(nodes[ID][3])




n = get_number()
p = get_number()

languages = []
nodes = dict()

for i in range(n):
    if get_word() == "I":
        id = get_number()-1
        character = get_word()
        yes_id = get_number()-1
        no_id = get_number()-1
        nodes[id] = [1,character,yes_id,no_id]
    else:
        id = get_number()-1
        lang = get_word()
        languages.append(lang)
        nodes[id] = [0,lang]

languages = set(languages)

for i in range(p):
    phrase = input()
    p_char = set(phrase)
    removed = []
    removed_char = []
    for key in nodes:
        node = nodes[key]
        if (node[0] == 1) and (node[1] in p_char):
            #Remove all descendants
            if node[1] in removed_char:
                continue
            remove_desc(node[3])


    final = []
    for language in languages:
        if language not in removed:
            final.append(language)
    final.sort()
    print(' '.join(final))