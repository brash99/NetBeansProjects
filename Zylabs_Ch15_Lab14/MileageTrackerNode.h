/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/cppFiles/file.h to edit this template
 */

/* 
 * File:   MileageTrackerNode.h
 * Author: 00465510
 *
 * Created on November 12, 2021, 1:49 PM
 */

#ifndef MILEAGETRACKERNODE_H
#define MILEAGETRACKERNODE_H

#include <string>
using namespace std;

class MileageTrackerNode {
   public:
      // Constructor
      MileageTrackerNode();

      // Destructor
      ~MileageTrackerNode();

      // Constructor
      MileageTrackerNode(double milesInit, string dateInit);

      // Constructor
      MileageTrackerNode(double milesInit, string dateInit, MileageTrackerNode* nextLoc);

      /* Insert node after this node.
      Before: this -- next
      After:  this -- node -- next
      */
      void InsertAfter(MileageTrackerNode* nodeLoc);

      // Get location pointed by nextNodeRef
      MileageTrackerNode* GetNext();

      void PrintNodeData();
   
   private:
      double miles;         // Node data
      string date;          // Node data
      MileageTrackerNode* nextNodeRef; // Reference to the next node
};

#endif /* MILEAGETRACKERNODE_H */

