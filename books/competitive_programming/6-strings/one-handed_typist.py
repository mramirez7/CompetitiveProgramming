#ACCEPTED
QWERTY = "4567890-=qwertyuiop[]asdfgjkl;'zxcvbm,./$%^&*()_+QWERTYUIOP{}ASDFGJKL:\"ZXCVBM<>?1"
DVOARK = "qjlmfp/[]456.orsuyb;=789aetdck-0zx,iwvg'QJLMFP?{}$%^>ORSUYB:+&*(AETDCK_)ZX<IWVG\"1"

translator = {QWERTY[x]: DVOARK[x] for x in range(len(QWERTY))}
while 1:
    output = ""
    try:
        line = input()
        for i in line:
            if i in translator.keys(): output += translator[i]
            else: output += i
        print (output)
    except EOFError:
        break