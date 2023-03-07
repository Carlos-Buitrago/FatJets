#define TestTreeModifierSelector_cxx
// The class definition in TestTreeModifierSelector.h has been generated automatically
// by the ROOT utility TTree::MakeSelector(). This class is derived
// from the ROOT class TSelector. For more information on the TSelector
// framework see $ROOTSYS/README/README.SELECTOR or the ROOT User Manual.


// The following methods are defined in this file:
//    Begin():        called every time a loop on the tree starts,
//                    a convenient place to create your histograms.
//    SlaveBegin():   called after Begin(), when on PROOF called only on the
//                    slave servers.
//    Process():      called for each event, in this function you decide what
//                    to read and fill your histograms.
//    SlaveTerminate: called at the end of the loop on the tree, when on PROOF
//                    called only on the slave servers.
//    Terminate():    called at the end of the loop on the tree,
//                    a convenient place to draw/fit your histograms.
//
// To use this file, try the following session on your Tree T:
//
// root> T->Process("TestTreeModifierSelector.C")
// root> T->Process("TestTreeModifierSelector.C","some options")
// root> T->Process("TestTreeModifierSelector.C+")
//


#include "TestTreeModifierSelector.h"
#include <TH2.h>
#include <TStyle.h>

void TestTreeModifierSelector::Begin(TTree * /*tree*/)
{
   // The Begin() function is called at the start of the query.
   // When running with PROOF Begin() is only called on the client.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();
}

void TestTreeModifierSelector::SlaveBegin(TTree * /*tree*/)
{
   // The SlaveBegin() function is called after the Begin() function.
   // When running with PROOF SlaveBegin() is called on each slave server.
   // The tree argument is deprecated (on PROOF 0 is passed).

   TString option = GetOption();

}

Bool_t TestTreeModifierSelector::Process(Long64_t entry)
{
   // The Process() function is called for each entry in the tree (or possibly
   // keyed object in the case of PROOF) to be processed. The entry argument
   // specifies which entry in the currently loaded tree is to be processed.
   // When processing keyed objects with PROOF, the object is already loaded
   // and is available via the fObject pointer.
   //
   // This function should contain the \"body\" of the analysis. It can contain
   // simple or elaborate selection criteria, run algorithms on the data
   // of the event and typically fill histograms.
   //
   // The processing can be stopped by calling Abort().
   //
   // Use fStatus to set the return value of TTree::Process().
   //
   // The return value is currently not used.

   fReader.SetLocalEntry(entry);

   std::cout << "Processing event numer " << entry << std::endl;


   /* for (int i = 0; i < Jet_PT.GetSize(); i++){ */
   /*   std::cout << "pT of Jet number " << i << " is " << Jet_PT[i] << std::endl; */
   /*   std::cout << "number of constituents for this jet is " << Jet_Constituents[i].GetEntries() << std::endl; */
   /*   total_constituents += Jet_Constituents[i].GetEntries(); */
   /*   for (int j = 0; j < Jet_Constituents[i].GetEntries(); j++){ */
   /*     /1* TRef* ref = (TRef*)Jet_Constituents[i].At(j); *1/ */
   /*     /1* Int_t index = ref->GetObject()->GetUniqueID(); *1/ */
   /*     /1* std::cout << "Index for constituent number " << j << " is " << index << std::endl; *1/ */
       
   /*     TObject *obj = Jet_Constituents[i].At(j); */
   /*     if (obj == 0){ */
   /*       std::cout << "constituent number " << j << " is not accesible" << std::endl; */
   /*     } */

   /*   } */
   /* } */

   for (int i = 0; i < Particle_PT.GetSize(); i++){
     for (int j = 0; j < Jet_PT.GetSize(); j++){
       if (sqrt((Particle_Eta[i] - Jet_Eta[j])*(Particle_Eta[i] - Jet_Eta[j]) + (Particle_Phi[i] - Jet_Phi[j])*(Particle_Phi[i] - Jet_Phi[j])) < 0.6 && Particle_PT[i] > 350.){
         particles_in_jets = particles_in_jets + 1;
         goto cnt1;
       }
     }
     cnt1:;
   }
   /* std::cout << "particles in jets for this event: " << particles_in_jets << std::endl; */

   for (int i = 0; i < Track_PT.GetSize(); i++){
     for (int j = 0; j < Jet_PT.GetSize(); j++){
       if (sqrt((Track_Eta[i] - Jet_Eta[j])*(Track_Eta[i] - Jet_Eta[j]) + (Track_Phi[i] - Jet_Phi[j])*(Track_Phi[i] - Jet_Phi[j])) < 0.6 && Track_PT[i] > 50.){
         tracks_in_jets = tracks_in_jets + 1;
         goto cnt2;
       }
     }
     cnt2:;
   }
   /* std::cout << "tracks in jets for this event: " << tracks_in_jets << std::endl; */

   for (int i = 0; i < Tower_ET.GetSize(); i++){
     for (int j = 0; j < Jet_PT.GetSize(); j++){
       if (sqrt((Tower_Eta[i] - Jet_Eta[j])*(Tower_Eta[i] - Jet_Eta[j]) + (Tower_Phi[i] - Jet_Phi[j])*(Tower_Phi[i] - Jet_Phi[j])) < 0.6 && Tower_ET[i] > 20.){
         towers_in_jets = towers_in_jets + 1;
         goto cnt3;
       }
     }
     cnt3:;
   }
   /* std::cout << "towers in jets for this event: " << towers_in_jets << std::endl; */


   return kTRUE;
}

void TestTreeModifierSelector::SlaveTerminate()
{
   // The SlaveTerminate() function is called after all entries or objects
   // have been processed. When running with PROOF SlaveTerminate() is called
   // on each slave server.

}

void TestTreeModifierSelector::Terminate()
{
   // The Terminate() function is the last function to be called during
   // a query. It always runs on the client, it can be used to present
   // the results graphically or save the results to file.
   
   /* std::cout << "The total number of constituents across all the events is: " << total_constituents << std::endl; */
   std::cout << "The total number of particles in jets is: " << particles_in_jets << std::endl;
   std::cout << "The total number of tracks in jets is: " << tracks_in_jets << std::endl;
   std::cout << "The total number of towers in jets is: " << towers_in_jets << std::endl;

}
