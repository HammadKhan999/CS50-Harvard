import csv
import sys


def main():
    #  Check for command-line usage
    if len(sys.argv) != 3:
        print("Usage: python dna.py data.csv sequence.txt")
        sys.exit(1)

    database = sys.argv[1]
    sequence = sys.argv[2]
    db = []
    headers = []
    seq_file = open(sequence, "r")
    reader_seq = seq_file.read()
    max = list()
    # Read database file into a variable
    with open(database) as database_file:
        read_db = csv.DictReader(database_file)
        db = list(read_db)
        headers = read_db.fieldnames[1:]

    #  Read DNA sequence file into a variable
    # Find longest match of each STR in DNA sequence
    for i in range(len(headers)):
        max.append(longest_match(reader_seq, headers[i]))
    values = list()
    matched = False

    for i in range(len(db)):
        rows = []
        for j in range(1, len(headers) + 1):
            rows.append(int(list(db[i].values())[j]))
        values.append(rows)

    # Check database for matching profiles
    for i in range(len(db)):
        if max == values[i]:
            person = list(db[i].values())[0]
            matched = True
    if matched == False:
        print("No match")
    else:
        print(person)
    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):
        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:
            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
