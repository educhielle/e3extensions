filename = 'cophee0c.log'
invalidChars = ['i', 'I', 'e', 'G', 'g', 'm', ' ']
# threshold = 3000000000
printer = 1024 * 1024 * 1024
subprinter = 64 * 1024 * 1024
counter = 0
with open(filename, 'r') as f:
    c = f.read(1)
    while c:
        # if counter % printer == 0:
        #     print(counter)
        # if counter % subprinter == 0:
        #     print('|', end='', flush=True)
        # # if counter > threshold:
        # #     exit(1)
        if c not in invalidChars:
            print(c, end='', flush=True)
        c = f.read(1)
        counter += 1
    # print('---')
