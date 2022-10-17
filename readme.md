# Lulu

![boardsource Lulu](https://i.imgur.com/tjvUoXTh.png)

build 

qmk compile -kb boardsource/lulu_via/rp2040 -km tkr0429 -bl uf2-split-left
qmk compile -kb boardsource/lulu_via/rp2040 -km tkr0429 -bl uf2-split-right

flash 

qmk flash -kb boardsource/lulu_via/rp2040 -km tkr0429 -bl uf2-split-left
qmk flash -kb boardsource/lulu_via/rp2040 -km tkr0429 -bl uf2-split-right
