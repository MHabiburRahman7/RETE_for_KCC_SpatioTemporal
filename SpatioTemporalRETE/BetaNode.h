#pragma once
#include "Node.h"
//#include "TerminalNode.h"
#include "SlidingWindow.h"
#include "ReteNet.h"
#include "SpatialOp.h"

#include "Utilities.h"

#include <string>
#include <queue>
//#include "../execution/EventProcess.h"

class BetaNode : public Node
{
public:
	//Function from Node
	int testNode(int TimeSlice);
	//int getID();
	string getType();
	Node* getSinglePair(int i);
	vector<Node*> getAllPairs();
	bool prevNodeAlreadyConnected();

	//bool isEmptyResult();
	void pushResult(queue<EventPtr> result, Node* inputNode);

	//BetaNode();
	BetaNode(int id, string condition);

	//connecting beta & terminal
	int addBetaPair(Node* pair);
	int checkBeta(Node* pair);

	//Init function
	int ClearConnection();
	int ResetNode();
	int ClearResult();
	int ClearInputQueue(bool isLeft);

	//getSet Function
	string getProduct();
	Node* getLeftConnNode();
	Node* getRightConnNode();
	string getLeftConnName();
	string getRightConnName();
	string getSpecialOpName();
	queue<EventPtr> getLeftInput();
	queue<EventPtr> getRightInput();

	float getSpatialLimFloat();

	void setWindow(int len, int step);
	void setMatchingKey(string newKey);
	void setAggregateCondition(string expression);

	int setLeftConnection(Node* node);
	int setRightConnection(Node* node);

	bool isEmptyResult();
	int justTest();
	void forcePushInQueue(EventPtr* result, bool toLeft = true);

	queue<EventPtr> getEvRes();

	//WINDOW PART
	void refreshEvent(queue<EventPtr>& inputEvent);
	int getExecutionEstimated();

private:
	//int id;
	string thisCondition; //AND OR
	string thisProduct; //Then expression or RHS
	string specialOperation, specialOperationLeft, specialOperationRight;
	string key = "id";

	pair<string, Node*> leftSourcePair, rightSourcePair, termPair;
	pair<queue<EventPtr>, Node*> leftInputQueue, rightInputQueue;

	queue<EventPtr> EventResult;
	//TerminalNode* terminalPair;

	//Connected Pairs 
	vector<Node*> listOfNextPair;

	//WINDOW PART
	//int winLen = -1, winSlide = -1;
	//long long nextTime = -1;
	SlidingWindow* win;

	//MISCS
	queue<Event> createdEvent;

	//Spatial Operator
	SpatialOp* thisSpatialOp;

	//Extra condition to handle exist, sum, and so on ._.

};

