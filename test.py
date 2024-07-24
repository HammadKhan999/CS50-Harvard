seven = 0
eight = 0

for i in range(len(Boston)):
    if Boston["rm"][i] >= 7 and Boston["rm"][i] < 8:
        eight += 1
    elif Boston["rm"][i] >= 8:
        seven += 1

print(" suburbs average more than seven rooms per dwelling:", seven)
print(" suburbs average more than eight rooms per dwelling:", eight)
