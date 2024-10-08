# -*- coding: UTF-8 -*-


# This file was *autogenerated* from the file pythontex-files-practica02/sage_default_default.sage
from sage.all_cmdline import *   # import sage library

_sage_const_1 = Integer(1); _sage_const_0 = Integer(0); _sage_const_2 = Integer(2); _sage_const_5 = Integer(5); _sage_const_3 = Integer(3); _sage_const_6 = Integer(6); _sage_const_8 = Integer(8); _sage_const_4 = Integer(4); _sage_const_9 = Integer(9); _sage_const_7 = Integer(7); _sage_const_12 = Integer(12); _sage_const_13 = Integer(13); _sage_const_11 = Integer(11)


import os
import sys
import codecs

if '--interactive' not in sys.argv[_sage_const_1 :]:
    if sys.version_info[_sage_const_0 ] == _sage_const_2 :
        sys.stdout = codecs.getwriter('UTF-8')(sys.stdout, 'strict')
        sys.stderr = codecs.getwriter('UTF-8')(sys.stderr, 'strict')
    else:
        sys.stdout = codecs.getwriter('UTF-8')(sys.stdout.buffer, 'strict')
        sys.stderr = codecs.getwriter('UTF-8')(sys.stderr.buffer, 'strict')

if '/usr/share/texlive/texmf-dist/scripts/pythontex' and '/usr/share/texlive/texmf-dist/scripts/pythontex' not in sys.path:
    sys.path.append('/usr/share/texlive/texmf-dist/scripts/pythontex')
from pythontex_utils import PythonTeXUtils
pytex = PythonTeXUtils()

pytex.docdir = os.getcwd()
if os.path.isdir('.'):
    os.chdir('.')
    if os.getcwd() not in sys.path:
        sys.path.append(os.getcwd())
else:
    if len(sys.argv) < _sage_const_2  or sys.argv[_sage_const_1 ] != '--manual':
        sys.exit('Cannot find directory .')
if pytex.docdir not in sys.path:
    sys.path.append(pytex.docdir)

pytex.formatter = latex


pytex.id = 'sage_default_default'
pytex.family = 'sage'
pytex.session = 'default'
pytex.restart = 'default'

pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '0'
pytex.line = '102'

print('=>PYTHONTEX:STDOUT#0#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#0#block#\n')
pytex.before()
A = matrix(QQ,[[_sage_const_1 ,-_sage_const_1 ,-_sage_const_5 ,-_sage_const_5 ],[-_sage_const_1 ,-_sage_const_1 ,_sage_const_2 ,_sage_const_1 ],[_sage_const_0 ,-_sage_const_1 ,-_sage_const_2 ,-_sage_const_3 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_0 ,_sage_const_1 ]])
B = matrix(QQ,[[_sage_const_6 ],[_sage_const_1 ],[_sage_const_5 ],[-_sage_const_2 ]])
AB = block_matrix([[A,B]])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '1'
pytex.line = '110'

print('=>PYTHONTEX:STDOUT#1#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#1#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '2'
pytex.line = '114'

print('=>PYTHONTEX:STDOUT#2#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#2#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '3'
pytex.line = '119'

print('=>PYTHONTEX:STDOUT#3#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#3#i#\n')
pytex.before()
print(pytex.formatter(R.subdivision(_sage_const_0 ,_sage_const_1 )))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '4'
pytex.line = '168'

print('=>PYTHONTEX:STDOUT#4#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#4#block#\n')
pytex.before()
A = matrix(QQ,[[_sage_const_2 ,-_sage_const_1 ,_sage_const_0 ],[_sage_const_1 ,_sage_const_0 ,-_sage_const_1 ],[_sage_const_0 ,_sage_const_1 ,_sage_const_0 ],[_sage_const_1 ,_sage_const_0 ,_sage_const_0 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_1 ]])
B = matrix(QQ,[[_sage_const_8 ],[-_sage_const_3 ],[-_sage_const_5 ],[_sage_const_2 ],[_sage_const_8 ]])
AB = block_matrix(_sage_const_1 ,_sage_const_2 ,[A,B])
R = copy(AB.echelon_form())
R.subdivide(_sage_const_3 ,_sage_const_3 )
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '5'
pytex.line = '177'

print('=>PYTHONTEX:STDOUT#5#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#5#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '6'
pytex.line = '177'

print('=>PYTHONTEX:STDOUT#6#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#6#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '7'
pytex.line = '184'

print('=>PYTHONTEX:STDOUT#7#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#7#block#\n')
pytex.before()
A1 = R.subdivision(_sage_const_0 ,_sage_const_0 )
A2 = R.subdivision(_sage_const_1 ,_sage_const_0 )
B1 = R.subdivision(_sage_const_0 ,_sage_const_1 )
B2 = R.subdivision(_sage_const_1 ,_sage_const_1 )
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '8'
pytex.line = '191'

print('=>PYTHONTEX:STDOUT#8#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#8#i#\n')
pytex.before()
print(pytex.formatter(R[:,:_sage_const_3 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '9'
pytex.line = '191'

print('=>PYTHONTEX:STDOUT#9#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#9#i#\n')
pytex.before()
print(pytex.formatter(R[:,_sage_const_3 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '10'
pytex.line = '193'

print('=>PYTHONTEX:STDOUT#10#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#10#i#\n')
pytex.before()
print(pytex.formatter(A1))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '11'
pytex.line = '193'

print('=>PYTHONTEX:STDOUT#11#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#11#i#\n')
pytex.before()
print(pytex.formatter(B1))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '12'
pytex.line = '193'

print('=>PYTHONTEX:STDOUT#12#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#12#i#\n')
pytex.before()
print(pytex.formatter(A2))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '13'
pytex.line = '193'

print('=>PYTHONTEX:STDOUT#13#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#13#i#\n')
pytex.before()
print(pytex.formatter(B2))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '14'
pytex.line = '218'

print('=>PYTHONTEX:STDOUT#14#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#14#block#\n')
pytex.before()
A = matrix(Zmod(_sage_const_5 ),[[_sage_const_0 ,_sage_const_0 ,_sage_const_0 ],[_sage_const_1 ,_sage_const_3 ,_sage_const_2 ],[_sage_const_4 ,_sage_const_1 ,_sage_const_1 ],[_sage_const_4 ,_sage_const_3 ,_sage_const_0 ],[_sage_const_4 ,_sage_const_3 ,_sage_const_0 ]])
B = matrix(Zmod(_sage_const_5 ),[[_sage_const_0 ],[_sage_const_0 ],[_sage_const_1 ],[_sage_const_3 ],[_sage_const_0 ]])
AB = block_matrix(_sage_const_1 ,_sage_const_2 ,[A,B])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '15'
pytex.line = '226'

print('=>PYTHONTEX:STDOUT#15#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#15#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '16'
pytex.line = '230'

print('=>PYTHONTEX:STDOUT#16#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#16#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '17'
pytex.line = '253'

print('=>PYTHONTEX:STDOUT#17#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#17#block#\n')
pytex.before()
A = matrix(QQ,[[_sage_const_0 ,-_sage_const_1 ,_sage_const_3 ],[_sage_const_1 ,-_sage_const_2 ,_sage_const_5 ],[_sage_const_1 ,-_sage_const_3 ,_sage_const_9 ],[_sage_const_1 ,-_sage_const_2 ,_sage_const_3 ],[_sage_const_2 ,-_sage_const_3 ,_sage_const_9 ]])
B = matrix(QQ,[[_sage_const_3 ],[_sage_const_3 ],[_sage_const_7 ],[_sage_const_1 ],[_sage_const_5 ]])
AB = block_matrix(_sage_const_1 ,_sage_const_2 ,[A,B])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '18'
pytex.line = '261'

print('=>PYTHONTEX:STDOUT#18#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#18#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '19'
pytex.line = '265'

print('=>PYTHONTEX:STDOUT#19#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#19#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '20'
pytex.line = '271'

print('=>PYTHONTEX:STDOUT#20#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#20#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_3 :,:_sage_const_3 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '21'
pytex.line = '271'

print('=>PYTHONTEX:STDOUT#21#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#21#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_3 :,_sage_const_3 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '22'
pytex.line = '274'

print('=>PYTHONTEX:STDOUT#22#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#22#i#\n')
pytex.before()
print(pytex.formatter(R[:_sage_const_3 ,:]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '23'
pytex.line = '277'

print('=>PYTHONTEX:STDOUT#23#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#23#i#\n')
pytex.before()
print(pytex.formatter(R[:_sage_const_3 ,_sage_const_3 ]))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '24'
pytex.line = '349'

print('=>PYTHONTEX:STDOUT#24#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#24#block#\n')
pytex.before()
A=matrix(Zmod(_sage_const_7 ),[[_sage_const_3 ,_sage_const_1 ,_sage_const_3 ,_sage_const_5 ,_sage_const_2 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_3 ,_sage_const_3 ,_sage_const_1 ],[_sage_const_0 ,_sage_const_0 ,_sage_const_0 ,_sage_const_0 ,_sage_const_4 ]])
B=column_matrix(Zmod(_sage_const_7 ),[_sage_const_3 ,_sage_const_1 ,_sage_const_12 ])
AB = block_matrix([[A,B]])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '25'
pytex.line = '357'

print('=>PYTHONTEX:STDOUT#25#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#25#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '26'
pytex.line = '361'

print('=>PYTHONTEX:STDOUT#26#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#26#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '27'
pytex.line = '375'

print('=>PYTHONTEX:STDOUT#27#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#27#block#\n')
pytex.before()
P = Zmod(_sage_const_7 )['alpha, beta']; (alpha, beta,) = P._first_ngens(2)
M = matrix(P,_sage_const_5 ,_sage_const_6 )
M[:_sage_const_3 ,:] = R
M[_sage_const_3 ,_sage_const_1 ] = _sage_const_1 
M[_sage_const_4 ,_sage_const_3 ] = _sage_const_1 
M[_sage_const_3 ,_sage_const_5 ] = alpha
M[_sage_const_4 ,_sage_const_5 ] = beta
M.subdivide([],_sage_const_5 )
MR = M.echelon_form()
X = MR.subdivision(_sage_const_0 ,_sage_const_1 )
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '28'
pytex.line = '403'

print('=>PYTHONTEX:STDOUT#28#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#28#i#\n')
pytex.before()
print(pytex.formatter(M))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '29'
pytex.line = '403'

print('=>PYTHONTEX:STDOUT#29#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#29#i#\n')
pytex.before()
print(pytex.formatter(MR))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '30'
pytex.line = '407'

print('=>PYTHONTEX:STDOUT#30#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#30#i#\n')
pytex.before()
print(pytex.formatter(X))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '31'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#31#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#31#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '32'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#32#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#32#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '33'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#33#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#33#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '34'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#34#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#34#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '35'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#35#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#35#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '36'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#36#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#36#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '37'
pytex.line = '415'

print('=>PYTHONTEX:STDOUT#37#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#37#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_0 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '38'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#38#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#38#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '39'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#39#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#39#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '40'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#40#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#40#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '41'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#41#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#41#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '42'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#42#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#42#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '43'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#43#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#43#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '44'
pytex.line = '416'

print('=>PYTHONTEX:STDOUT#44#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#44#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_1 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '45'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#45#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#45#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '46'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#46#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#46#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '47'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#47#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#47#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '48'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#48#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#48#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '49'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#49#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#49#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '50'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#50#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#50#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '51'
pytex.line = '417'

print('=>PYTHONTEX:STDOUT#51#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#51#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_2 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '52'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#52#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#52#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '53'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#53#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#53#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '54'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#54#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#54#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '55'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#55#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#55#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '56'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#56#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#56#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '57'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#57#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#57#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '58'
pytex.line = '418'

print('=>PYTHONTEX:STDOUT#58#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#58#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_3 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '59'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#59#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#59#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '60'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#60#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#60#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '61'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#61#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#61#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '62'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#62#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#62#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '63'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#63#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#63#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '64'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#64#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#64#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '65'
pytex.line = '419'

print('=>PYTHONTEX:STDOUT#65#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#65#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_4 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '66'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#66#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#66#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '67'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#67#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#67#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '68'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#68#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#68#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '69'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#69#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#69#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '70'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#70#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#70#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '71'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#71#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#71#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '72'
pytex.line = '420'

print('=>PYTHONTEX:STDOUT#72#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#72#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_5 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '73'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#73#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#73#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_0 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '74'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#74#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#74#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_1 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '75'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#75#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#75#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_2 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '76'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#76#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#76#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_3 ) ))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '77'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#77#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#77#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_4 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '78'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#78#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#78#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_5 )))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '79'
pytex.line = '421'

print('=>PYTHONTEX:STDOUT#79#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#79#i#\n')
pytex.before()
print(pytex.formatter(X(alpha=_sage_const_6 ,beta=_sage_const_6 )))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '80'
pytex.line = '465'

print('=>PYTHONTEX:STDOUT#80#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#80#block#\n')
pytex.before()
P = QQ['a, b']; (a, b,) = P._first_ngens(2)
A =  matrix(P,[[_sage_const_1 ,_sage_const_1 ,_sage_const_1 ,_sage_const_0 ,-_sage_const_2 ],
[_sage_const_3 ,_sage_const_1 ,_sage_const_2 ,_sage_const_0 ,-_sage_const_4 ],
[-_sage_const_3 ,_sage_const_0 ,-_sage_const_1 ,_sage_const_0 ,_sage_const_1 ],
[-_sage_const_3 ,_sage_const_1 ,_sage_const_0 ,_sage_const_0 ,-_sage_const_2 ],
[-_sage_const_2 ,_sage_const_0 ,-_sage_const_1 ,_sage_const_0 ,_sage_const_2 ]])
B =  matrix(P,[[a-b],[-_sage_const_13 ],[b],[-_sage_const_11 ],[-a]])
AB = block_matrix([[A,B]])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '81'
pytex.line = '477'

print('=>PYTHONTEX:STDOUT#81#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#81#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '82'
pytex.line = '477'

print('=>PYTHONTEX:STDOUT#82#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#82#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '83'
pytex.line = '480'

print('=>PYTHONTEX:STDOUT#83#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#83#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_3 :,:_sage_const_5 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '84'
pytex.line = '480'

print('=>PYTHONTEX:STDOUT#84#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#84#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_3 :,_sage_const_5 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '85'
pytex.line = '482'

print('=>PYTHONTEX:STDOUT#85#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#85#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_3 :,_sage_const_5 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '86'
pytex.line = '483'

print('=>PYTHONTEX:STDOUT#86#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#86#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_3 ,_sage_const_5 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '87'
pytex.line = '484'

print('=>PYTHONTEX:STDOUT#87#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#87#i#\n')
pytex.before()
print(pytex.formatter(R[_sage_const_4 ,_sage_const_5 ]))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '88'
pytex.line = '488'

print('=>PYTHONTEX:STDOUT#88#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#88#block#\n')
pytex.before()
R1 = R(a=-_sage_const_6 ,b=_sage_const_1 )
R1.subdivide(_sage_const_3 ,_sage_const_5 )
R2 = R1[:_sage_const_3 ,:]
R2.subdivide([],_sage_const_5 )
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '89'
pytex.line = '494'

print('=>PYTHONTEX:STDOUT#89#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#89#i#\n')
pytex.before()
print(pytex.formatter(R1))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '90'
pytex.line = '499'

print('=>PYTHONTEX:STDOUT#90#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#90#i#\n')
pytex.before()
print(pytex.formatter(R2))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '91'
pytex.line = '506'

print('=>PYTHONTEX:STDOUT#91#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#91#block#\n')
pytex.before()
Q = QQ['alpha, beta']; (alpha, beta,) = Q._first_ngens(2)
M = matrix(Q,_sage_const_5 ,_sage_const_6 )
M.subdivide([],_sage_const_5 )
M[:_sage_const_3 ,:] = R2
M[_sage_const_3 ,_sage_const_3 ] = _sage_const_1 
M[_sage_const_4 ,_sage_const_4 ] = _sage_const_1 
M[_sage_const_3 ,_sage_const_5 ] = alpha
M[_sage_const_4 ,_sage_const_5 ] = beta
MR = M.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '92'
pytex.line = '519'

print('=>PYTHONTEX:STDOUT#92#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#92#i#\n')
pytex.before()
print(pytex.formatter(M))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '93'
pytex.line = '519'

print('=>PYTHONTEX:STDOUT#93#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#93#i#\n')
pytex.before()
print(pytex.formatter(MR))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '94'
pytex.line = '521'

print('=>PYTHONTEX:STDOUT#94#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#94#i#\n')
pytex.before()
print(pytex.formatter(MR[:,_sage_const_5 ]))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '95'
pytex.line = '553'

print('=>PYTHONTEX:STDOUT#95#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#95#block#\n')
pytex.before()
P = Zmod(_sage_const_5 )['a, b']; (a, b,) = P._first_ngens(2)
A = matrix(P,[[_sage_const_1 ,_sage_const_3 ,_sage_const_0 ],[_sage_const_3 ,_sage_const_3 ,_sage_const_0 ],[_sage_const_1 ,_sage_const_3 ,_sage_const_2 ],[_sage_const_2 ,_sage_const_1 ,_sage_const_0 ],[_sage_const_3 ,_sage_const_0 ,_sage_const_3 ]])
B = matrix(P,[[a,_sage_const_4 ],[_sage_const_3 ,_sage_const_4 ],[_sage_const_0 ,b],[_sage_const_2 *a,b],[_sage_const_4 ,a]])
AB = block_matrix([[A,B]])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '96'
pytex.line = '561'

print('=>PYTHONTEX:STDOUT#96#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#96#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '97'
pytex.line = '561'

print('=>PYTHONTEX:STDOUT#97#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#97#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '98'
pytex.line = '569'

print('=>PYTHONTEX:STDOUT#98#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#98#block#\n')
pytex.before()
R1 = R(a = _sage_const_1 , b = _sage_const_3 )
R1.subdivide(_sage_const_3 ,_sage_const_3 )
R2 = R1[:_sage_const_3 ,:]
R2.subdivide(_sage_const_3 ,_sage_const_3 )
X = R2.subdivision(_sage_const_0 ,_sage_const_1 )
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '99'
pytex.line = '577'

print('=>PYTHONTEX:STDOUT#99#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#99#i#\n')
pytex.before()
print(pytex.formatter(R1))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '100'
pytex.line = '579'

print('=>PYTHONTEX:STDOUT#100#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#100#i#\n')
pytex.before()
print(pytex.formatter(R2))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '101'
pytex.line = '580'

print('=>PYTHONTEX:STDOUT#101#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#101#i#\n')
pytex.before()
print(pytex.formatter(X))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '102'
pytex.line = '606'

print('=>PYTHONTEX:STDOUT#102#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#102#block#\n')
pytex.before()
A = matrix(QQ,[[-_sage_const_2 ,_sage_const_2 ,_sage_const_2 ,-_sage_const_2 ,-_sage_const_1 ],[_sage_const_0 ,_sage_const_1 /_sage_const_2 ,_sage_const_1 ,_sage_const_1 ,_sage_const_1 ],[_sage_const_0 ,_sage_const_1 ,-_sage_const_1 ,_sage_const_2 ,_sage_const_0 ]])
B = matrix(QQ,[[-_sage_const_5 ,_sage_const_5 ],[_sage_const_2 ,_sage_const_3 ],[-_sage_const_3 ,-_sage_const_2 ]])
AB = block_matrix([[A,B]])
R = AB.echelon_form()
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '103'
pytex.line = '614'

print('=>PYTHONTEX:STDOUT#103#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#103#i#\n')
pytex.before()
print(pytex.formatter(AB))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '104'
pytex.line = '614'

print('=>PYTHONTEX:STDOUT#104#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#104#i#\n')
pytex.before()
print(pytex.formatter(R))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '105'
pytex.line = '621'

print('=>PYTHONTEX:STDOUT#105#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#105#block#\n')
pytex.before()
P = QQ['alpha1, alpha2, alpha3, alpha4']; (alpha1, alpha2, alpha3, alpha4,) = P._first_ngens(4)
M = matrix(P,_sage_const_5 ,_sage_const_7 )
M[:_sage_const_3 ,:] = R
M[_sage_const_3 ,_sage_const_3 ] = _sage_const_1 
M[_sage_const_4 ,_sage_const_4 ] = _sage_const_1 
M[_sage_const_3 ,_sage_const_5 ] = alpha1
M[_sage_const_3 ,_sage_const_6 ] = alpha2
M[_sage_const_4 ,_sage_const_5 ] = alpha3
M[_sage_const_4 ,_sage_const_6 ] = alpha4
M.subdivide([],_sage_const_5 )
MR = M.echelon_form()
X = MR.subdivision(_sage_const_0 ,_sage_const_1 )
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '106'
pytex.line = '635'

print('=>PYTHONTEX:STDOUT#106#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#106#i#\n')
pytex.before()
print(pytex.formatter(M))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '107'
pytex.line = '635'

print('=>PYTHONTEX:STDOUT#107#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#107#i#\n')
pytex.before()
print(pytex.formatter(MR))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '108'
pytex.line = '637'

print('=>PYTHONTEX:STDOUT#108#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#108#i#\n')
pytex.before()
print(pytex.formatter(X))
pytex.after()


pytex.cleanup()

