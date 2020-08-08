s = input()
# Write an answer using print
# To debug: print("Debug messages...", file=sys.stderr, flush=True)

for c in len(s):
    if(s[c - 1] == ' ' and s[c].isalpha()) print(s[c].upper(),end='')
    elif(s[c]==' ') print(' ',end='')
    elif print(s[c].lower(),end='')