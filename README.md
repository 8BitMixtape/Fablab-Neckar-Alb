# Fablab-Neckar-Alb

# 8Bit MixTape parts placement
![8Bit-MixTape-Neckar-Alb](https://raw.githubusercontent.com/8BitMixtape/Fablab-Neckar-Alb/master/8Bit-MixTape/images/8Bit-MixTape_partLayout.jpg)

# Berliner Schule 8Step MixTape parts placement
![Berliner Schule 8Step Sequencer](https://raw.githubusercontent.com/8BitMixtape/Fablab-Neckar-Alb/master/8Step-MixTape/images/8Step-MixTape_partsPlacing.jpg)

# Tribute to Klaus

((((t>>2)&(t>>11))|(((t>>2))&(t>>13)))&15)*15
(((((t/3)&((t/2)>>12)))^(((t/2)&((t/3)>>9))))&15)*15
(((((t)&((t/3)>>8)))^(((t/3)&((t/9)>>11))))&15)*15
(((((t/9)&((t/3)>>8)))^(((t/3)&((t/9)>>11))))&15)*15 +++
(((((t/9)&((t/1)>>8)))|(((t/3)&((t/1)>>11))))&15)*15 ++
(((((t/5)&((t/1)>>8)))|(((t/3)&((t/1)>>11))))&15)*15

(((((t/9)&((t/3)>>8)))^(((t/3)&((t/9)>>11))))&15)*15
1,2,3,4,5 klingen gut miteinander ausser 4+5

etwas anders:
(((((t>>8)&((t%((t>>9)&15)))))|(((t>>5)&((t%((t>>10)&15))))))&15)*15
(((((t>>9)&((t%((t>>11)&15)))))|(((t>>5)&((t%((t>>8)&15))))))&15)*15
((((t>>7)&(t>>10))&15 & ((t>>0)%((
((t>>11)&1)*8+((t>>12)&1)*4+((t>>13)&1)*2+((t>>9)&1)*1     )&15)) )&15)*15
(((((t>>8)&(t>>6))&15) &
((t>>0)%((((t>>11)&8)|((t>>10)&4)|((t>>9)&2)|((t>>11)&1))) ) )&15)*15
(((((t>>7)&1)|((t>>9)&2)|((t>>3)&4)|((t>>10)&8)) &
((t>>1)%((((t>>5)&8)|((t>>10)&4)|((t>>9)&2)|((t>>11)&1))) ) )&15)*15
( ( (((t>>7)&1)|((t>>9)&2)|((t>>3)&4)|((t>>10)&8)) &
(t^((t>>7)&8)|((t>>10)&4)|((t>>9)&2)|((t>>12)&1)) )&15)*15
( ((((t>>4)&1)|((t>>3)&2)|((t>>1)&4)|((t>>3)&8)) %
(((t>>12)&8)|((t>>11)&4)|((t>>9)&2)|((t>>10)&1)) )&15)*15
((  (t%((((t>>5)&8)|((t>>11)&4)|((t>>9)&2)|((t>>10)&1))) ) )&15)*15
( (t%((t>>8)&15) )&15)*15
(  (((t>>11)&15)) & ((t%((t>>6)&15)) ))*15
(   ((((t>>4)&15))) & ((t%((t>>10)&15)) ))*15
(   ((((t>>10)&15))) & ((t%((t>>3)&15)) ))*15
(  ((t%((t>>9)&15))) &  (((t>>12)&1)|((t>>13)&2)|((t>>9)&4)|((t>>9)&8)
))*15

4 aus t xor t%n
(((((t>>10)&1)|((t>>11)&2)|((t>>12)&4)|((t>>13)&8)) ^
(((t>>2)%((((t>>14)&4)|((t>>13)&2)|((t>>11)&1)))) ) )&15)*15
(((((t>>10)&1)|((t>>10)&2)|((t>>10)&4)|((t>>10)&8)) ^
(((t>>2)%((((t>>12)&4)|((t>>11)&2)|((t>>10)&1)))) ) )&15)*15
(((((t>>12)&1)|((t>>9)&2)|((t>>10)&4)|((t>>8)&8)) ^
(((t>>2)%((((t>>13)&4)|((t>>13)&2)|((t>>11)&1)))) ) )&15)*15
(((((t>>9)&1)|((t>>7)&2)|((t>>10)&4)|((t>>10)&8)) ^
(((t>>1)%((((t>>12)&4)|((t>>10)&2)|((t>>9)&1)))) ) )&15)*15

mit swapper
(((((t&16)?((t>>12)&1):(((t>>12)&1)<<1))|((t&16)?((t>>9)&2):(((t>>9)&2)>>1))|((t&32)?((t>>10)&4):(((t>>10)&4)<<1))|((t&32)?((t>>8)&8):(((t>>8)&8)>>1)))^(((t>>2)%((((t>>13)&4)|((t>>13)&2)|((t>>11)&1))))))&15)*15
15*( ((t&16)?(t&1):((t&1)<<1)) | ((t&16)?(t&2):((t&2)>>1)) |
((t&32)?(t&4):((t&4)<<1)) | ((t&32)?(t&8):((t&8)>>1)))

für 4046 an r2r
(( (t>>1)%(
(((t>>11)&(t>>10))&8)|(((t>>9)&(t>>11))&4)|(((t>>9)&(t>>12))&2)|(((t>>10)^(t>>9))&1)
) )&15)*15

beat4
((
(((t>>3)&((t>>0)%(t>>8))&8))|(((t>>4)&((t>>0)%(t>>8))&4))|(((t>>7)&((t>>0)%(t>>8))&2))|(((t>>11)&((t>>0)%(t>>8))&1))
)&15)*15
R-2R auf 4046 statt frequenzteiler?

( (((t>>9)&1)|((t>>10)&2)|((t>>8)&4)|((t>>9)&8)) &
((((t/3)&1)|((t/4)&2)|((t/5)&4)|((t/6)&8) ) )&15)*15 beautiful wechsel der
/n terme

lange periode
(( ((t/((t>>15)&1?3:2)) & ((t>>11))) |  (((t/((t>>17)&1?5:6))) & ((t>>13)))
 )&15)*15
sehr schön
(( ((t/((t>>15)&1?3:2))& ((t>>9)))  |  (((t/((t>>16)&1?5:6))) & ((t>>12)))
)&15)*15
sehr sehr schön
(( ((t/((t>>14)&1?3:2))& ((t>>11)))  |  (((t/((t>>16)&1?5:6))) & ((t>>9)))
)&15)*15
(( ((t/((t>>13)&1?2:3))& ((t>>12)))  |  (((t/((t>>12)&1?5:6))) & ((t>>10)))
)&15)*15
sehr lange periode und schön
(( ((t/((t>>13)&1?5:6))& ((t>>(((t/5)>>13)&1?8:10)))) |
(((t/((t>>12)&1?2:3))) & ((t>>(((t/7)>>12)&1?9:12))))  )&15)*15
(( ((t/((t>>11)&1?5:6))& ((t>>(((t/5)>>12)&1?8:10)))) |
(((t/((t>>12)&1?2:3))) & ((t>>(((t/6)>>10)&1?11:12))))  )&15)*15
(( ((t/((t>> 10..14 )&1?3:2)) & ((t>>(((t/32)>> 6..12 )&1? 9..14 )))) |
(((t/((t>>12)&1?5:6))) & ((t>>(((t/32)>>12)&1?12:10))))  )&15)*15


(( ((t/((t>>(((9+((t>>15)&3))&1)))?3:4)) & (t>>((9+((t>>16)&3))))) |
((t/((t>>(((9+((t>>17)&3))&1)))?5:6)) & (t>>((9+((t>>18)&3)))))  )&15)*15

(( (((t/(1+((t>>12)&3))) ) & (t>>((9+((t>>16)&3))))) |
(((t/(1+((t>>14)&3))) ) & (t>>((9+((t>>18)&3)))))  )&15)*15

(( (((t/(4+((t>>12)&6))) ) & (t>>((9+((t>>16)&3))))) |
(((t/(4+((t>>14)&6))) ) & (t>>((9+((t>>18)&3)))))  )&1)*100
(( (((t/(2+((t>>12)&3))) ) & (t>>((10+((t>>16)&3))))) |
(((t/(2+((t>>14)&3))) ) & (t>>((10+((t>>18)&3)))))  )&1)*100 tiefer
(( ( (t/( ((t>>12)&3)==0?3:((t>>12)&3)==1?4:((t>>12)&3)==2?6:8) ) &
(t>>((10+((t>>16)&3))))) | ((t/(
((t>>14)&3)==0?3:((t>>14)&3)==1?4:((t>>14)&3)==2?6:8)) &
(t>>((10+((t>>18)&3)))))  )&1)*100
(( ( (t/( ((t>>12)&3)==0?6:((t>>12)&3)==1?8:((t>>12)&3)==2?12:16) ) &
(t>>((10+((t>>16)&3))))) | ((t/(
((t>>14)&3)==0?6:((t>>14)&3)==1?8:((t>>14)&3)==2?12:16)) &
(t>>((10+((t>>18)&3)))))  )&1)*100

nibblebeat hardware simulation
(( ( (t/( ((t>>12)&3)==0?6:((t>>12)&3)==1?8:((t>>12)&3)==2?12:16) ) &
(t>>((10+((t>>16)&3))))) | ((t/(
((t>>14)&3)==0?6:((t>>14)&3)==1?8:((t>>14)&3)==2?12:16)) &
(t>>((11+((t>>18)&1)))))  )&1)*100

(( ((t/(((t>>12)&3)==0?6:((t>>12)&3)==1?8:((t>>12)&3)==2?12:16)) &
(t>>((9+((t>>14)&1))))) |
((t/(((t>>12)&3)==0?8:((t>>12)&3)==1?12:((t>>12)&3)==2?16:16)) &
(t>>((12+((t>>15)&1)))))  )&1)*100

simpler
((((t/3)&(t>>11))|((t/5)&(t>>13)))&7)*30

((((t/3)&(((t>>11)&1)|((t>>12)&2)|((t>>9)&4)))|((t/5)&(((t>>10)&1)|((t>>8)&2)|((t>>11)&4))))&7)*30
(( ((t/3)&(t>>11)) | ((t/2)&(t>>10)) )&1)*100

((((t/3)&((((t/4)>>11)&1)|(((t/4)>>12)&2)|(((t/4)>>9)&4)))|((t/4)&((((t/3)>>10)&1)|(((t/3)>>8)&2)|(((t/3)>>11)&4))))&7)*30
((((t/3)&((((t/4)>>11)&1)|(((t/4)>>12)&2)|(((t/4)>>9)&4)))|((t/4)&((((t/4)>>10)&1)|(((t/4)>>8)&2)|(((t/4)>>11)&4))))&7)*30
((((t/3)&((((t/4)>>11)&1)|(((t/4)>>12)&2)|(((t/4)>>9)&4)))|((t/4)&~((((t/4)>>10)&1)|(((t/4)>>8)&2)|(((t/4)>>11)&4))))&7)*30

variable dividers super gut, >1min play !!!
((((t/(2+((t>>17)&3)))&(((t>>11)&1)|((t>>12)&2)|((t>>9)&4)))|((t/(2+((t>>15)&3)))&(((t>>10)&1)|((t>>8)&2)|((t>>11)&4))))&7)*30

((((t/4)&(t>>12))|((t/3)&((((t>>13)%5)==0?2:((t>>13)%5)==1?5:((t>>13)%5)==2?3:((t>>13)%5)==3?6:5))))&7)*30

((((t/4)&(t>>12))|((t/3)&((((t>>11)%6)==0?7:((t>>11)%6)==1?7:((t>>11)%6)==2?6:((t>>11)%6)==3?4:((t>>11)%6)==4?1:3))))&7)*30

((((t/4)&(t>>12))|((t/3)&((((t>>12)%7)==0?1:((t>>12)%7)==1?3:((t>>12)%7)==2?7:((t>>12)%7)==3?7:((t>>12)%7)==4?6:((t>>12)%7)==5?4:0))))&7)*30

((((t/4)&(t>>11))|((t/3)&((((t>>13)%8)==0?1:((t>>13)%8)==1?1:((t>>13)%8)==2?3:((t>>13)%8)==3?7:((t>>13)%8)==4?7:((t>>13)%8)==5?6:((t>>13)%8)==6?4:0))))&7)*30
