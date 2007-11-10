#ifndef MEAWS_EXERCISE_DISPATCHER_H
#define MEAWS_EXERCISE_DISPATCHER_H

#include "defs.h"
#include "intonation-exercise.h"
#include "rhythm-exercise.h"
//#include "exerciseControl.h"
//#include "exerciseShift.h"
#include "backend.h"

#include <QDialog>
#include <QFileDialog>
#include <QImage>
#include <QLabel>
#include <QtGui>

class ExerciseDispatcher : public QDialog
{
	Q_OBJECT

public:
	ExerciseDispatcher(QFrame *getCentralFrame);
	~ExerciseDispatcher();

	QString getMessage();

public slots:
	void open();
	void close();
	void toggleAttempt();
	void setAttempt(bool running);
	bool openAttempt();

	void playFile();

	void analyze();
	void analysisDone(); // even tempier

	void addTry()
	{
		exercise_->addTry();
	};
	void delTry()
	{
		exercise_->delTry();
	};

signals:
	void enableActions(int state);
//	void attemptRunning(bool running);

private:
	bool chooseEvaluation();

	// basic GUI frames
	QVBoxLayout *layout_;
	QFrame *instructionArea_;
	QFrame *resultArea_;

	// actual Meaws objects
	Exercise *exercise_;
	MarBackend *marBackend_;

	// left-over garbage (?)
	QString exerciseName_;
	bool attemptRunningBool_;

	QString statusMessage_;
};
#endif

