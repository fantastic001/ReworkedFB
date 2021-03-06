#ifndef MODEL_H
#define MODEL_H



class Model
{
private:

    int numberOfObservedVars;
    int numberOfPossibleStatesZ;
    int numberOfPossibleStatesX;
    int numberOfIterations;

    double **emissionProbs; // Emission probs
    double **transitionProbs; // Transitiom probs
    double *P; //probs for Z1 to take some of the possible states
    int *X; // array of inputs
    double *C; //array for normalization


    double **alpha; //forward part
    double **beta; // backward part

    void initializeC();// allocates space for C

    void initializeAlpha();// allocates space for Alpha and sets all values in alpha to 0

    void initializeBeta();// allocates space for Beta and sets all values in beta to 0


    void computeAlpha();// forward part

    void computeBeta();// backward part


    void fit();//computes new Pi, new T, new E

public:

    Model(int m_observedVars, int m_statesZ, int m_statesX, int *m_X, double *m_P, double **m_T, double ** m_E, int m_Iter):
        numberOfObservedVars(m_observedVars), numberOfPossibleStatesZ(m_statesZ), numberOfPossibleStatesX(m_statesX), X(m_X),
        P(m_P), transitionProbs(m_T), emissionProbs(m_E), numberOfIterations(m_Iter){}


    void printNumberOfVars();
    void printNumberOfPossibleStatesZ();
    void printNumberOfPossibleStatesX();
    void printX();
    void printP();
    void printTrans();
    void printEmission();
    void printNumberOfIterations();
    void printAlpha();
    void printBeta();
    void printC();


    int getNumberOfObservedVars();
    void setNumberOfObservedVars(int m_setNumberOfObservedVars);


    int getNumberOfPossibleStatesZ();
    void setNumberOfPossibleStatesZ(int m_setNumberOfPossibleStatesZ);


    int getNumberOfPossibleStatesX();
    void setNumberOfPossibleStatesX(int m_setNumberOfPossibleStatesX);


    double *getP();
    void setP(double * m_P);


    double **getTransitonMatrix();
    void setTransitionMatrix(double **m_transitionProbs);


    double **getEmissionMatrix();
    void setEmissionMatrix (double **m_emissionProbs);


    int *getArrayX();
    void *setArrayX(int *m_X);



    void testPi();
    void predict();
};


#endif // MODEL_H

