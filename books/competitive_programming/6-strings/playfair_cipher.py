from string import ascii_uppercase

n = int(input())
while n:
    n -= 1
    table = input().strip().upper()
    table_ = []
    st = set(["Q"])
    for a in table:
        if a in ascii_uppercase and a not in st:
            st.add(a)
            table_.append(a)
    for a in ascii_uppercase:
        if a not in st:
            table_.append(a)
    dic = {table_[X]: X for X in range(len(table_))}
    text = "".join(input().strip().split(" ")).upper()
    pointer = 0
    ans = ""
    while pointer < len(text):
        first = text[pointer]
        pointer += 1
        if pointer == len(text) or text[pointer] == first:
            second = "X"
        else:
            second = text[pointer]
            pointer += 1
        #misma col
        if dic[first]%5 == dic[second]%5:
            if dic[first] + 5 >= len(table_):
                ans += table_[dic[first]%5]
            else:
                ans += table_[dic[first]+5]
            if dic[second] + 5 >= len(table_):
                ans += table_[dic[second]%5]
            else:
                ans += table_[dic[second]+5]
        #misma row
        elif dic[first]//5 == dic[second]//5:
            if dic[first]%5 == 4:
                ans += table_[dic[first]-4]
            else:
                ans += table_[dic[first]+1]
            if dic[second]%5 == 4:
                ans += table_[dic[second]-4]
            else:
                ans += table_[dic[second]+1]
        else:
            ans += table_[(dic[first]//5)*5+dic[second]%5]
            ans += table_[(dic[second]//5)*5+dic[first]%5]
    print (ans)


