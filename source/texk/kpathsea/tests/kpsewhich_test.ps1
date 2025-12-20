
kpsewhich.exe --var-value=TEXMFCNF
echo $?

kpsewhich.exe --var-value=TEXMFMAIN
echo $?

kpsewhich.exe --expand-var=$TEXMFMAIN
echo $?

kpsewhich.exe --all plain
echo $?

kpsewhich.exe afmtest.afm
echo $?

kpsewhich.exe plain.bst
echo $?
