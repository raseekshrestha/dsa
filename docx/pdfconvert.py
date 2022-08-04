import docx2pdf
import sys
import os

args = list()

for each in sys.argv[1:]:
    if not each.endswith(".docx"):
        args.append(each+".docx")
    else:
        args.append(each)

dirs = os.listdir()

diff = set(args).difference(set(dirs))
if len(diff) > 0:
    for each in diff:
        print(f"\t'{each}' not found in current Directory")


inter = set(args).intersection(set(dirs))
for index,each in enumerate(inter):
    docx2pdf.convert(each)
    print(f"""Coverted {each} to {each.replace(".docx",".pdf")} """)

