OPT = -Wall

uni:	main.o School.o Course.o CourseArray.o Registration.o RegList.o Student.o StuArray.o View.o Control.o
	g++ $(OPT) -o uni main.o School.o Course.o CourseArray.o Registration.o RegList.o Student.o StuArray.o View.o Control.o

main.o:	main.cc Control.h
	g++ $(OPT) -c main.cc

School.o: School.cc School.h CourseArray.h Student.h RegList.h
	g++ $(OPT) -c School.cc

Course.o: Course.cc Course.h
	g++ $(OPT) -c Course.cc

CourseArray.o: CourseArray.cc CourseArray.h Course.h
	g++ $(OPT) -c CourseArray.cc

Registration.o: Registration.cc Registration.h Student.h Course.h
	g++ $(OPT) -c Registration.cc

RegList.o: RegList.cc RegList.h Registration.h
	g++ $(OPT) -c RegList.cc

Student.o: Student.cc Student.h
	g++ $(OPT) -c Student.cc

StuArray.o: StuArray.cc StuArray.h Student.h
	g++ $(OPT) -c StuArray.cc

View.o: View.cc View.h
	g++ $(OPT) -c View.cc

Control.o: Control.cc Control.h School.h View.h
	g++ $(OPT) -c Control.cc

clean:
	rm -f *.o uni
