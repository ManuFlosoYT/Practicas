# -*- coding: UTF-8 -*-


# This file was *autogenerated* from the file pythontex-files-Tarea2D3D/sage_default_default.sage
from sage.all_cmdline import *   # import sage library

_sage_const_1 = Integer(1); _sage_const_0 = Integer(0); _sage_const_2 = Integer(2); _sage_const_0p171527754943673 = RealNumber('0.171527754943673'); _sage_const_0p886777920259044 = RealNumber('0.886777920259044'); _sage_const_0p326362780186830 = RealNumber('0.326362780186830'); _sage_const_0p0162571041668937 = RealNumber('0.0162571041668937'); _sage_const_0p923172294747017 = RealNumber('0.923172294747017'); _sage_const_0p586214584852305 = RealNumber('0.586214584852305'); _sage_const_0p717434104560504 = RealNumber('0.717434104560504'); _sage_const_0p503600818995866 = RealNumber('0.503600818995866'); _sage_const_0p274834075678966 = RealNumber('0.274834075678966'); _sage_const_3 = Integer(3); _sage_const_6 = Integer(6); _sage_const_4 = Integer(4); _sage_const_5 = Integer(5)


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

pytex.command = 'code'
pytex.set_context('')
pytex.args = ''
pytex.instance = '0'
pytex.line = '22'

print('=>PYTHONTEX:STDOUT#0#code#')
sys.stderr.write('=>PYTHONTEX:STDERR#0#code#\n')
pytex.before()
latex.matrix_delimiters("[", "]")
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '1'
pytex.line = '37'

print('=>PYTHONTEX:STDOUT#1#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#1#block#\n')
pytex.before()
H = matrix(RR,[[-_sage_const_0p171527754943673 ,-_sage_const_0p886777920259044 ,-_sage_const_0p326362780186830 ],
[_sage_const_0p0162571041668937 ,_sage_const_0p923172294747017 ,_sage_const_0p586214584852305 ]])
Pol = PolynomialRing(RR, names=('x', 'y', 'z',)); (x, y, z,) = Pol._first_ngens(3)
Ecuaciones = H*column_matrix(Pol,[x,y,z])
b = vector(RR,[_sage_const_0p717434104560504 ,_sage_const_0p503600818995866 ,_sage_const_0p274834075678966 ])
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '2'
pytex.line = '50'

print('=>PYTHONTEX:STDOUT#2#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#2#i#\n')
pytex.before()
print(pytex.formatter(Ecuaciones[_sage_const_0 ,_sage_const_0 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '3'
pytex.line = '50'

print('=>PYTHONTEX:STDOUT#3#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#3#i#\n')
pytex.before()
print(pytex.formatter(Ecuaciones[_sage_const_1 ,_sage_const_0 ]))
pytex.after()
pytex.command = 'i'
pytex.set_context('')
pytex.args = ''
pytex.instance = '4'
pytex.line = '50'

print('=>PYTHONTEX:STDOUT#4#i#')
sys.stderr.write('=>PYTHONTEX:STDERR#4#i#\n')
pytex.before()
print(pytex.formatter(column_matrix(b)))
pytex.after()
pytex.command = 'block'
pytex.set_context('')
pytex.args = ''
pytex.instance = '5'
pytex.line = '95'

print('=>PYTHONTEX:STDOUT#5#block#')
sys.stderr.write('=>PYTHONTEX:STDERR#5#block#\n')
pytex.before()

H = matrix(RR,[[-_sage_const_0p171527754943673 ,-_sage_const_0p886777920259044 ,-_sage_const_0p326362780186830 ],
               [_sage_const_0p0162571041668937 ,_sage_const_0p923172294747017  ,_sage_const_0p586214584852305  ]])
Pol = PolynomialRing(RR, names=('x', 'y', 'z',)); (x, y, z,) = Pol._first_ngens(3)
Ecuaciones = H*column_matrix(Pol,[x,y,z])
b = vector(RR,[_sage_const_0p717434104560504 ,_sage_const_0p503600818995866 ,_sage_const_0p274834075678966 ])

v1 = H.row(_sage_const_0 )
v2 = H.row(_sage_const_1 )
w1 = v1
w3 = v1.cross_product(v2)
w2 = w1.cross_product(w3)
u1 = w1/norm(w1)
u2 = w2/norm(w2)
u3 = w3/norm(w3)
pb = b-(b*u1)*u1-(b*u2)*u2
c = b+_sage_const_3 *u3
a = _sage_const_2 *pi/_sage_const_6 
B = column_matrix([u1, u2, u3])
GC = matrix(RR, [[cos(a), -sin(a), _sage_const_0 ], [sin(a), cos(a), _sage_const_0 ], [_sage_const_0 , _sage_const_0 , _sage_const_1 ]])
G = B*GC*B**-_sage_const_1 
BP = [G**i*b for i in range(_sage_const_6 )]
pc = pb+_sage_const_3 *u3
C = [G**i*c for i in range(_sage_const_6 )]

pytex.after()
pytex.command = 'sub'
pytex.set_context('')
pytex.args = ''
pytex.instance = '6'
pytex.line = '123'

print('=>PYTHONTEX:STDOUT#6#sub#')
sys.stderr.write('=>PYTHONTEX:STDERR#6#sub#\n')
pytex.before()
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_0 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_1 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_2 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_3 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_4 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_5 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_0 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_0 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_1 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_1 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_1 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_1 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_2 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_2 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_2 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_2 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_3 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_3 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_3 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_3 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_4 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_4 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_4 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_4 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_5 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_5 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_5 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_5 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_0 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(BP[_sage_const_0 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_0 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_1 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_2 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_3 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_4 ])
print('=>PYTHONTEX:FIELD_DELIM#')
print(C[_sage_const_5 ])
pytex.after()


pytex.cleanup()

