package test;

import java.util.Random;
import java.io.BufferedReader;
import java.io.FileReader;
import weka.core.Instances;
import weka.classifiers.Evaluation;
import weka.classifiers.trees.J48;
import weka.classifiers.bayes.NaiveBayes;

public class Classifier {
	public static void main(String[] args) throws Exception {
		Instances data = new Instances(new BufferedReader(new FileReader("src/test.arff")));

		int nTrain = (int) Math.round(data.numInstances() * 0.6666666667);
		int nTest = data.numInstances() - nTrain;
		data.randomize(new Random(0));
		Instances train = new Instances(data, 0, nTrain), test = new Instances(data, nTrain, nTest);
		train.setClassIndex(train.numAttributes()-1);
		test.setClassIndex(test.numAttributes()-1);

		J48 c45Classifier = new J48();
		c45Classifier.setOptions(null);
		c45Classifier.buildClassifier(train);

		NaiveBayes nbClassifier = new NaiveBayes();
		nbClassifier.setOptions(null);
		nbClassifier.buildClassifier(train);

		Evaluation eval = new Evaluation(train);
		eval.evaluateModel(c45Classifier, test);
		System.out.println("\nDECISION TREE:\n"+eval.toSummaryString("\nSummary:\n", false)+
		  eval.toMatrixString("\nConfustion Matrix:\n")+"\nF[1] measure: "+eval.fMeasure(1));
		eval.evaluateModel(nbClassifier, test);
		System.out.println("\nNAIVE BAYES:\n"+eval.toSummaryString("\nSummary:\n", false)+
		  eval.toMatrixString("\nConfustion Matrix:\n")+"\nF[1] measure: "+eval.fMeasure(1));
	}
}

