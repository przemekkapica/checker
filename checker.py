import os

# filenames below
code1 = 'code1.cpp'
code2 = 'code2.cpp'

def compile(file_name):
    t = os.system('g++ -o {} {}'.format(file_name[:-4], file_name))
    if t == 0:
        print(file_name + ' compiled succesfuly')
    else:
        print('error compiling ' + file_name)
        sys.exit()

def compare():
    tests_number = len([f for f in os.listdir('/home/przemek/python/checker/input')])
    for i in range(1, tests_number + 1):
        os.system('./{} < input/{}.in > output-1/{}.out'.format(code1[:-4], i, i))
        os.system('./{} < input/{}.in > output-2/{}.out'.format(code2[:-4], i, i))
        output_1 = open('output-1/{}.out'.format(i))
        output_2 = open('output-2/{}.out'.format(i))
        if (output_1.read() == output_2.read()):
            print('test{}: ok'.format(i))
        else:
            print('test{}: wrong answer'.format(i))


if __name__ == '__main__':
    compile(code1)
    compile(code2)
    compare()
