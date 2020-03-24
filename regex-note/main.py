import re
import sys

pattern = "^api/.*|api/?$"
string = sys.argv[1]


if len(sys.argv) == 3:
	pattern = sys.argv[1]
	string = sys.argv[2]

# regex
regex = re.compile(pattern)
response = regex.match(string)

print('\npattern: ' + pattern + '\nstring: ' + string + '\n')
print('Matched') if response else print('Nope!')