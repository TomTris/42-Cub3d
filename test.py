

f = open("test.ber", "w")

len = 100

for i in range(len):
    f.write("1")
f.write("\n")

for i in range(len):
    f.write("1")
    for e in range(len - 2):
        f.write("0")
    f.write("1")
    f.write("\n")

for i in range(len):
    f.write("1")
f.write("\n")

f.close()