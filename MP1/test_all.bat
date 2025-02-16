@echo off
for %%f in (c1\03-C1\*orig.txt) do (
    echo Processing %%f...
    "bin/03-C2.exe" < "%%f" > "output\%%~nf.txt"
)
echo Done!