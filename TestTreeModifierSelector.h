//////////////////////////////////////////////////////////
// This class has been automatically generated on
// Sun Mar  5 15:26:00 2023 by ROOT version 6.26/10
// from TTree Delphes/Analysis tree
// found on file: pp_tt_hadronic_14TeV500kEvtsGenCutT350_CutQCD350_InclusiveCut350_delphes_events.root
//////////////////////////////////////////////////////////

#ifndef TestTreeModifierSelector_h
#define TestTreeModifierSelector_h

#include <TROOT.h>
#include <TChain.h>
#include <TFile.h>
#include <TSelector.h>
#include <TTreeReader.h>
#include <TTreeReaderValue.h>
#include <TTreeReaderArray.h>

// Headers needed by this particular selector
#include "TClonesArray.h"

#include <vector>



class TestTreeModifierSelector : public TSelector {
public :
   TTreeReader     fReader;  //!the tree reader
   TTree          *fChain = 0;   //!pointer to the analyzed TTree or TChain

   // Readers to access the data (delete the ones you do not need).
   TTreeReaderArray<unsigned int> Event_fUniqueID = {fReader, "Event.fUniqueID"};
   TTreeReaderArray<unsigned int> Event_fBits = {fReader, "Event.fBits"};
   TTreeReaderArray<Long64_t> Event_Number = {fReader, "Event.Number"};
   TTreeReaderArray<Float_t> Event_ReadTime = {fReader, "Event.ReadTime"};
   TTreeReaderArray<Float_t> Event_ProcTime = {fReader, "Event.ProcTime"};
   TTreeReaderArray<Int_t> Event_ProcessID = {fReader, "Event.ProcessID"};
   TTreeReaderArray<Int_t> Event_MPI = {fReader, "Event.MPI"};
   TTreeReaderArray<Float_t> Event_Weight = {fReader, "Event.Weight"};
   TTreeReaderArray<Float_t> Event_CrossSection = {fReader, "Event.CrossSection"};
   TTreeReaderArray<Float_t> Event_CrossSectionError = {fReader, "Event.CrossSectionError"};
   TTreeReaderArray<Float_t> Event_Scale = {fReader, "Event.Scale"};
   TTreeReaderArray<Float_t> Event_AlphaQED = {fReader, "Event.AlphaQED"};
   TTreeReaderArray<Float_t> Event_AlphaQCD = {fReader, "Event.AlphaQCD"};
   TTreeReaderArray<Int_t> Event_ID1 = {fReader, "Event.ID1"};
   TTreeReaderArray<Int_t> Event_ID2 = {fReader, "Event.ID2"};
   TTreeReaderArray<Float_t> Event_X1 = {fReader, "Event.X1"};
   TTreeReaderArray<Float_t> Event_X2 = {fReader, "Event.X2"};
   TTreeReaderArray<Float_t> Event_ScalePDF = {fReader, "Event.ScalePDF"};
   TTreeReaderArray<Float_t> Event_PDF1 = {fReader, "Event.PDF1"};
   TTreeReaderArray<Float_t> Event_PDF2 = {fReader, "Event.PDF2"};
   TTreeReaderValue<Int_t> Event_size = {fReader, "Event_size"};
   TTreeReaderArray<unsigned int> Weight_fUniqueID = {fReader, "Weight.fUniqueID"};
   TTreeReaderArray<unsigned int> Weight_fBits = {fReader, "Weight.fBits"};
   TTreeReaderArray<Float_t> Weight_Weight = {fReader, "Weight.Weight"};
   TTreeReaderValue<Int_t> Weight_size = {fReader, "Weight_size"};
   TTreeReaderArray<unsigned int> Particle_fUniqueID = {fReader, "Particle.fUniqueID"};
   TTreeReaderArray<unsigned int> Particle_fBits = {fReader, "Particle.fBits"};
   TTreeReaderArray<Int_t> Particle_PID = {fReader, "Particle.PID"};
   TTreeReaderArray<Int_t> Particle_Status = {fReader, "Particle.Status"};
   TTreeReaderArray<Int_t> Particle_IsPU = {fReader, "Particle.IsPU"};
   TTreeReaderArray<Int_t> Particle_M1 = {fReader, "Particle.M1"};
   TTreeReaderArray<Int_t> Particle_M2 = {fReader, "Particle.M2"};
   TTreeReaderArray<Int_t> Particle_D1 = {fReader, "Particle.D1"};
   TTreeReaderArray<Int_t> Particle_D2 = {fReader, "Particle.D2"};
   TTreeReaderArray<Int_t> Particle_Charge = {fReader, "Particle.Charge"};
   TTreeReaderArray<Float_t> Particle_Mass = {fReader, "Particle.Mass"};
   TTreeReaderArray<Float_t> Particle_E = {fReader, "Particle.E"};
   TTreeReaderArray<Float_t> Particle_Px = {fReader, "Particle.Px"};
   TTreeReaderArray<Float_t> Particle_Py = {fReader, "Particle.Py"};
   TTreeReaderArray<Float_t> Particle_Pz = {fReader, "Particle.Pz"};
   TTreeReaderArray<Float_t> Particle_P = {fReader, "Particle.P"};
   TTreeReaderArray<Float_t> Particle_PT = {fReader, "Particle.PT"};
   TTreeReaderArray<Float_t> Particle_Eta = {fReader, "Particle.Eta"};
   TTreeReaderArray<Float_t> Particle_Phi = {fReader, "Particle.Phi"};
   TTreeReaderArray<Float_t> Particle_Rapidity = {fReader, "Particle.Rapidity"};
   TTreeReaderArray<Float_t> Particle_T = {fReader, "Particle.T"};
   TTreeReaderArray<Float_t> Particle_X = {fReader, "Particle.X"};
   TTreeReaderArray<Float_t> Particle_Y = {fReader, "Particle.Y"};
   TTreeReaderArray<Float_t> Particle_Z = {fReader, "Particle.Z"};
   TTreeReaderValue<Int_t> Particle_size = {fReader, "Particle_size"};
   TTreeReaderArray<unsigned int> Track_fUniqueID = {fReader, "Track.fUniqueID"};
   TTreeReaderArray<unsigned int> Track_fBits = {fReader, "Track.fBits"};
   TTreeReaderArray<Int_t> Track_PID = {fReader, "Track.PID"};
   TTreeReaderArray<Int_t> Track_Charge = {fReader, "Track.Charge"};
   TTreeReaderArray<Float_t> Track_P = {fReader, "Track.P"};
   TTreeReaderArray<Float_t> Track_PT = {fReader, "Track.PT"};
   TTreeReaderArray<Float_t> Track_Eta = {fReader, "Track.Eta"};
   TTreeReaderArray<Float_t> Track_Phi = {fReader, "Track.Phi"};
   TTreeReaderArray<Float_t> Track_CtgTheta = {fReader, "Track.CtgTheta"};
   TTreeReaderArray<Float_t> Track_C = {fReader, "Track.C"};
   TTreeReaderArray<Float_t> Track_Mass = {fReader, "Track.Mass"};
   TTreeReaderArray<Float_t> Track_EtaOuter = {fReader, "Track.EtaOuter"};
   TTreeReaderArray<Float_t> Track_PhiOuter = {fReader, "Track.PhiOuter"};
   TTreeReaderArray<Float_t> Track_T = {fReader, "Track.T"};
   TTreeReaderArray<Float_t> Track_X = {fReader, "Track.X"};
   TTreeReaderArray<Float_t> Track_Y = {fReader, "Track.Y"};
   TTreeReaderArray<Float_t> Track_Z = {fReader, "Track.Z"};
   TTreeReaderArray<Float_t> Track_TOuter = {fReader, "Track.TOuter"};
   TTreeReaderArray<Float_t> Track_XOuter = {fReader, "Track.XOuter"};
   TTreeReaderArray<Float_t> Track_YOuter = {fReader, "Track.YOuter"};
   TTreeReaderArray<Float_t> Track_ZOuter = {fReader, "Track.ZOuter"};
   TTreeReaderArray<Float_t> Track_Xd = {fReader, "Track.Xd"};
   TTreeReaderArray<Float_t> Track_Yd = {fReader, "Track.Yd"};
   TTreeReaderArray<Float_t> Track_Zd = {fReader, "Track.Zd"};
   TTreeReaderArray<Float_t> Track_L = {fReader, "Track.L"};
   TTreeReaderArray<Float_t> Track_D0 = {fReader, "Track.D0"};
   TTreeReaderArray<Float_t> Track_DZ = {fReader, "Track.DZ"};
   TTreeReaderArray<Float_t> Track_Nclusters = {fReader, "Track.Nclusters"};
   TTreeReaderArray<Float_t> Track_dNdx = {fReader, "Track.dNdx"};
   TTreeReaderArray<Float_t> Track_ErrorP = {fReader, "Track.ErrorP"};
   TTreeReaderArray<Float_t> Track_ErrorPT = {fReader, "Track.ErrorPT"};
   TTreeReaderArray<Float_t> Track_ErrorPhi = {fReader, "Track.ErrorPhi"};
   TTreeReaderArray<Float_t> Track_ErrorCtgTheta = {fReader, "Track.ErrorCtgTheta"};
   TTreeReaderArray<Float_t> Track_ErrorT = {fReader, "Track.ErrorT"};
   TTreeReaderArray<Float_t> Track_ErrorD0 = {fReader, "Track.ErrorD0"};
   TTreeReaderArray<Float_t> Track_ErrorDZ = {fReader, "Track.ErrorDZ"};
   TTreeReaderArray<Float_t> Track_ErrorC = {fReader, "Track.ErrorC"};
   TTreeReaderArray<Float_t> Track_ErrorD0Phi = {fReader, "Track.ErrorD0Phi"};
   TTreeReaderArray<Float_t> Track_ErrorD0C = {fReader, "Track.ErrorD0C"};
   TTreeReaderArray<Float_t> Track_ErrorD0DZ = {fReader, "Track.ErrorD0DZ"};
   TTreeReaderArray<Float_t> Track_ErrorD0CtgTheta = {fReader, "Track.ErrorD0CtgTheta"};
   TTreeReaderArray<Float_t> Track_ErrorPhiC = {fReader, "Track.ErrorPhiC"};
   TTreeReaderArray<Float_t> Track_ErrorPhiDZ = {fReader, "Track.ErrorPhiDZ"};
   TTreeReaderArray<Float_t> Track_ErrorPhiCtgTheta = {fReader, "Track.ErrorPhiCtgTheta"};
   TTreeReaderArray<Float_t> Track_ErrorCDZ = {fReader, "Track.ErrorCDZ"};
   TTreeReaderArray<Float_t> Track_ErrorCCtgTheta = {fReader, "Track.ErrorCCtgTheta"};
   TTreeReaderArray<Float_t> Track_ErrorDZCtgTheta = {fReader, "Track.ErrorDZCtgTheta"};
   TTreeReaderArray<TRef> Track_Particle = {fReader, "Track.Particle"};
   TTreeReaderArray<Int_t> Track_VertexIndex = {fReader, "Track.VertexIndex"};
   TTreeReaderValue<Int_t> Track_size = {fReader, "Track_size"};
   TTreeReaderArray<unsigned int> Tower_fUniqueID = {fReader, "Tower.fUniqueID"};
   TTreeReaderArray<unsigned int> Tower_fBits = {fReader, "Tower.fBits"};
   TTreeReaderArray<Float_t> Tower_ET = {fReader, "Tower.ET"};
   TTreeReaderArray<Float_t> Tower_Eta = {fReader, "Tower.Eta"};
   TTreeReaderArray<Float_t> Tower_Phi = {fReader, "Tower.Phi"};
   TTreeReaderArray<Float_t> Tower_E = {fReader, "Tower.E"};
   TTreeReaderArray<Float_t> Tower_T = {fReader, "Tower.T"};
   TTreeReaderArray<Int_t> Tower_NTimeHits = {fReader, "Tower.NTimeHits"};
   TTreeReaderArray<Float_t> Tower_Eem = {fReader, "Tower.Eem"};
   TTreeReaderArray<Float_t> Tower_Ehad = {fReader, "Tower.Ehad"};
   TTreeReaderArray<TRefArray> Tower_Particles = {fReader, "Tower.Particles"};
   TTreeReaderValue<Int_t> Tower_size = {fReader, "Tower_size"};
   TTreeReaderArray<unsigned int> EFlowTrack_fUniqueID = {fReader, "EFlowTrack.fUniqueID"};
   TTreeReaderArray<unsigned int> EFlowTrack_fBits = {fReader, "EFlowTrack.fBits"};
   TTreeReaderArray<Int_t> EFlowTrack_PID = {fReader, "EFlowTrack.PID"};
   TTreeReaderArray<Int_t> EFlowTrack_Charge = {fReader, "EFlowTrack.Charge"};
   TTreeReaderArray<Float_t> EFlowTrack_P = {fReader, "EFlowTrack.P"};
   TTreeReaderArray<Float_t> EFlowTrack_PT = {fReader, "EFlowTrack.PT"};
   TTreeReaderArray<Float_t> EFlowTrack_Eta = {fReader, "EFlowTrack.Eta"};
   TTreeReaderArray<Float_t> EFlowTrack_Phi = {fReader, "EFlowTrack.Phi"};
   TTreeReaderArray<Float_t> EFlowTrack_CtgTheta = {fReader, "EFlowTrack.CtgTheta"};
   TTreeReaderArray<Float_t> EFlowTrack_C = {fReader, "EFlowTrack.C"};
   TTreeReaderArray<Float_t> EFlowTrack_Mass = {fReader, "EFlowTrack.Mass"};
   TTreeReaderArray<Float_t> EFlowTrack_EtaOuter = {fReader, "EFlowTrack.EtaOuter"};
   TTreeReaderArray<Float_t> EFlowTrack_PhiOuter = {fReader, "EFlowTrack.PhiOuter"};
   TTreeReaderArray<Float_t> EFlowTrack_T = {fReader, "EFlowTrack.T"};
   TTreeReaderArray<Float_t> EFlowTrack_X = {fReader, "EFlowTrack.X"};
   TTreeReaderArray<Float_t> EFlowTrack_Y = {fReader, "EFlowTrack.Y"};
   TTreeReaderArray<Float_t> EFlowTrack_Z = {fReader, "EFlowTrack.Z"};
   TTreeReaderArray<Float_t> EFlowTrack_TOuter = {fReader, "EFlowTrack.TOuter"};
   TTreeReaderArray<Float_t> EFlowTrack_XOuter = {fReader, "EFlowTrack.XOuter"};
   TTreeReaderArray<Float_t> EFlowTrack_YOuter = {fReader, "EFlowTrack.YOuter"};
   TTreeReaderArray<Float_t> EFlowTrack_ZOuter = {fReader, "EFlowTrack.ZOuter"};
   TTreeReaderArray<Float_t> EFlowTrack_Xd = {fReader, "EFlowTrack.Xd"};
   TTreeReaderArray<Float_t> EFlowTrack_Yd = {fReader, "EFlowTrack.Yd"};
   TTreeReaderArray<Float_t> EFlowTrack_Zd = {fReader, "EFlowTrack.Zd"};
   TTreeReaderArray<Float_t> EFlowTrack_L = {fReader, "EFlowTrack.L"};
   TTreeReaderArray<Float_t> EFlowTrack_D0 = {fReader, "EFlowTrack.D0"};
   TTreeReaderArray<Float_t> EFlowTrack_DZ = {fReader, "EFlowTrack.DZ"};
   TTreeReaderArray<Float_t> EFlowTrack_Nclusters = {fReader, "EFlowTrack.Nclusters"};
   TTreeReaderArray<Float_t> EFlowTrack_dNdx = {fReader, "EFlowTrack.dNdx"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorP = {fReader, "EFlowTrack.ErrorP"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorPT = {fReader, "EFlowTrack.ErrorPT"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorPhi = {fReader, "EFlowTrack.ErrorPhi"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorCtgTheta = {fReader, "EFlowTrack.ErrorCtgTheta"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorT = {fReader, "EFlowTrack.ErrorT"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorD0 = {fReader, "EFlowTrack.ErrorD0"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorDZ = {fReader, "EFlowTrack.ErrorDZ"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorC = {fReader, "EFlowTrack.ErrorC"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorD0Phi = {fReader, "EFlowTrack.ErrorD0Phi"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorD0C = {fReader, "EFlowTrack.ErrorD0C"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorD0DZ = {fReader, "EFlowTrack.ErrorD0DZ"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorD0CtgTheta = {fReader, "EFlowTrack.ErrorD0CtgTheta"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorPhiC = {fReader, "EFlowTrack.ErrorPhiC"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorPhiDZ = {fReader, "EFlowTrack.ErrorPhiDZ"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorPhiCtgTheta = {fReader, "EFlowTrack.ErrorPhiCtgTheta"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorCDZ = {fReader, "EFlowTrack.ErrorCDZ"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorCCtgTheta = {fReader, "EFlowTrack.ErrorCCtgTheta"};
   TTreeReaderArray<Float_t> EFlowTrack_ErrorDZCtgTheta = {fReader, "EFlowTrack.ErrorDZCtgTheta"};
   TTreeReaderArray<TRef> EFlowTrack_Particle = {fReader, "EFlowTrack.Particle"};
   TTreeReaderArray<Int_t> EFlowTrack_VertexIndex = {fReader, "EFlowTrack.VertexIndex"};
   TTreeReaderValue<Int_t> EFlowTrack_size = {fReader, "EFlowTrack_size"};
   TTreeReaderArray<unsigned int> EFlowPhoton_fUniqueID = {fReader, "EFlowPhoton.fUniqueID"};
   TTreeReaderArray<unsigned int> EFlowPhoton_fBits = {fReader, "EFlowPhoton.fBits"};
   TTreeReaderArray<Float_t> EFlowPhoton_ET = {fReader, "EFlowPhoton.ET"};
   TTreeReaderArray<Float_t> EFlowPhoton_Eta = {fReader, "EFlowPhoton.Eta"};
   TTreeReaderArray<Float_t> EFlowPhoton_Phi = {fReader, "EFlowPhoton.Phi"};
   TTreeReaderArray<Float_t> EFlowPhoton_E = {fReader, "EFlowPhoton.E"};
   TTreeReaderArray<Float_t> EFlowPhoton_T = {fReader, "EFlowPhoton.T"};
   TTreeReaderArray<Int_t> EFlowPhoton_NTimeHits = {fReader, "EFlowPhoton.NTimeHits"};
   TTreeReaderArray<Float_t> EFlowPhoton_Eem = {fReader, "EFlowPhoton.Eem"};
   TTreeReaderArray<Float_t> EFlowPhoton_Ehad = {fReader, "EFlowPhoton.Ehad"};
   TTreeReaderArray<TRefArray> EFlowPhoton_Particles = {fReader, "EFlowPhoton.Particles"};
   TTreeReaderValue<Int_t> EFlowPhoton_size = {fReader, "EFlowPhoton_size"};
   TTreeReaderArray<unsigned int> EFlowNeutralHadron_fUniqueID = {fReader, "EFlowNeutralHadron.fUniqueID"};
   TTreeReaderArray<unsigned int> EFlowNeutralHadron_fBits = {fReader, "EFlowNeutralHadron.fBits"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_ET = {fReader, "EFlowNeutralHadron.ET"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_Eta = {fReader, "EFlowNeutralHadron.Eta"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_Phi = {fReader, "EFlowNeutralHadron.Phi"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_E = {fReader, "EFlowNeutralHadron.E"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_T = {fReader, "EFlowNeutralHadron.T"};
   TTreeReaderArray<Int_t> EFlowNeutralHadron_NTimeHits = {fReader, "EFlowNeutralHadron.NTimeHits"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_Eem = {fReader, "EFlowNeutralHadron.Eem"};
   TTreeReaderArray<Float_t> EFlowNeutralHadron_Ehad = {fReader, "EFlowNeutralHadron.Ehad"};
   TTreeReaderArray<TRefArray> EFlowNeutralHadron_Particles = {fReader, "EFlowNeutralHadron.Particles"};
   TTreeReaderValue<Int_t> EFlowNeutralHadron_size = {fReader, "EFlowNeutralHadron_size"};
   TTreeReaderArray<unsigned int> GenJet_fUniqueID = {fReader, "GenJet.fUniqueID"};
   TTreeReaderArray<unsigned int> GenJet_fBits = {fReader, "GenJet.fBits"};
   TTreeReaderArray<Float_t> GenJet_PT = {fReader, "GenJet.PT"};
   TTreeReaderArray<Float_t> GenJet_Eta = {fReader, "GenJet.Eta"};
   TTreeReaderArray<Float_t> GenJet_Phi = {fReader, "GenJet.Phi"};
   TTreeReaderArray<Float_t> GenJet_T = {fReader, "GenJet.T"};
   TTreeReaderArray<Float_t> GenJet_Mass = {fReader, "GenJet.Mass"};
   TTreeReaderArray<Float_t> GenJet_DeltaEta = {fReader, "GenJet.DeltaEta"};
   TTreeReaderArray<Float_t> GenJet_DeltaPhi = {fReader, "GenJet.DeltaPhi"};
   TTreeReaderArray<unsigned int> GenJet_Flavor = {fReader, "GenJet.Flavor"};
   TTreeReaderArray<unsigned int> GenJet_FlavorAlgo = {fReader, "GenJet.FlavorAlgo"};
   TTreeReaderArray<unsigned int> GenJet_FlavorPhys = {fReader, "GenJet.FlavorPhys"};
   TTreeReaderArray<unsigned int> GenJet_BTag = {fReader, "GenJet.BTag"};
   TTreeReaderArray<unsigned int> GenJet_BTagAlgo = {fReader, "GenJet.BTagAlgo"};
   TTreeReaderArray<unsigned int> GenJet_BTagPhys = {fReader, "GenJet.BTagPhys"};
   TTreeReaderArray<unsigned int> GenJet_TauTag = {fReader, "GenJet.TauTag"};
   TTreeReaderArray<Float_t> GenJet_TauWeight = {fReader, "GenJet.TauWeight"};
   TTreeReaderArray<Int_t> GenJet_Charge = {fReader, "GenJet.Charge"};
   TTreeReaderArray<Float_t> GenJet_EhadOverEem = {fReader, "GenJet.EhadOverEem"};
   TTreeReaderArray<Int_t> GenJet_NCharged = {fReader, "GenJet.NCharged"};
   TTreeReaderArray<Int_t> GenJet_NNeutrals = {fReader, "GenJet.NNeutrals"};
   TTreeReaderArray<Float_t> GenJet_NeutralEnergyFraction = {fReader, "GenJet.NeutralEnergyFraction"};
   TTreeReaderArray<Float_t> GenJet_ChargedEnergyFraction = {fReader, "GenJet.ChargedEnergyFraction"};
   TTreeReaderArray<Float_t> GenJet_Beta = {fReader, "GenJet.Beta"};
   TTreeReaderArray<Float_t> GenJet_BetaStar = {fReader, "GenJet.BetaStar"};
   TTreeReaderArray<Float_t> GenJet_MeanSqDeltaR = {fReader, "GenJet.MeanSqDeltaR"};
   TTreeReaderArray<Float_t> GenJet_PTD = {fReader, "GenJet.PTD"};
   TTreeReaderArray<TLorentzVector> GenJet_SoftDroppedJet = {fReader, "GenJet.SoftDroppedJet"};
   TTreeReaderArray<TLorentzVector> GenJet_SoftDroppedSubJet1 = {fReader, "GenJet.SoftDroppedSubJet1"};
   TTreeReaderArray<TLorentzVector> GenJet_SoftDroppedSubJet2 = {fReader, "GenJet.SoftDroppedSubJet2"};
   TTreeReaderArray<unsigned int> GenJet_TrimmedP4 = {fReader, "GenJet.TrimmedP4[5]"};
   TTreeReaderArray<unsigned int> GenJet_PrunedP4 = {fReader, "GenJet.PrunedP4[5]"};
   TTreeReaderArray<unsigned int> GenJet_SoftDroppedP4 = {fReader, "GenJet.SoftDroppedP4[5]"};
   TTreeReaderArray<unsigned int> GenJet_NSubJetsTrimmed = {fReader, "GenJet.NSubJetsTrimmed"};
   TTreeReaderArray<Double_t> GenJet_NSubJetsPruned = {fReader, "GenJet.NSubJetsPruned"};
   TTreeReaderArray<Double_t> GenJet_NSubJetsSoftDropped = {fReader, "GenJet.NSubJetsSoftDropped"};
   TTreeReaderArray<Double_t> GenJet_ExclYmerge23 = {fReader, "GenJet.ExclYmerge23"};
   TTreeReaderArray<unsigned int> GenJet_ExclYmerge45 = {fReader, "GenJet.ExclYmerge45"};
   TTreeReaderArray<unsigned int> GenJet_ExclYmerge56 = {fReader, "GenJet.ExclYmerge56"};
   TTreeReaderArray<unsigned int> GenJet_Constituents = {fReader, "GenJet.Constituents"};
   TTreeReaderArray<unsigned int> GenJet_Particles = {fReader, "GenJet.Particles"};
   TTreeReaderArray<Double_t> GenJet_Area = {fReader, "GenJet.Area"};
   TTreeReaderValue<Int_t> GenJet_size = {fReader, "GenJet_size"};
   TTreeReaderArray<unsigned int> GenMissingET_fUniqueID = {fReader, "GenMissingET.fUniqueID"};
   TTreeReaderArray<unsigned int> GenMissingET_fBits = {fReader, "GenMissingET.fBits"};
   TTreeReaderArray<Float_t> GenMissingET_MET = {fReader, "GenMissingET.MET"};
   TTreeReaderArray<Float_t> GenMissingET_Eta = {fReader, "GenMissingET.Eta"};
   TTreeReaderArray<Float_t> GenMissingET_Phi = {fReader, "GenMissingET.Phi"};
   TTreeReaderValue<Int_t> GenMissingET_size = {fReader, "GenMissingET_size"};
   TTreeReaderArray<unsigned int> Jet_fUniqueID = {fReader, "Jet.fUniqueID"};
   TTreeReaderArray<unsigned int> Jet_fBits = {fReader, "Jet.fBits"};
   TTreeReaderArray<Float_t> Jet_PT = {fReader, "Jet.PT"};
   TTreeReaderArray<Float_t> Jet_Eta = {fReader, "Jet.Eta"};
   TTreeReaderArray<Float_t> Jet_Phi = {fReader, "Jet.Phi"};
   TTreeReaderArray<Float_t> Jet_T = {fReader, "Jet.T"};
   TTreeReaderArray<Float_t> Jet_Mass = {fReader, "Jet.Mass"};
   TTreeReaderArray<Float_t> Jet_DeltaEta = {fReader, "Jet.DeltaEta"};
   TTreeReaderArray<Float_t> Jet_DeltaPhi = {fReader, "Jet.DeltaPhi"};
   TTreeReaderArray<unsigned int> Jet_Flavor = {fReader, "Jet.Flavor"};
   TTreeReaderArray<unsigned int> Jet_FlavorAlgo = {fReader, "Jet.FlavorAlgo"};
   TTreeReaderArray<unsigned int> Jet_FlavorPhys = {fReader, "Jet.FlavorPhys"};
   TTreeReaderArray<unsigned int> Jet_BTag = {fReader, "Jet.BTag"};
   TTreeReaderArray<unsigned int> Jet_BTagAlgo = {fReader, "Jet.BTagAlgo"};
   TTreeReaderArray<unsigned int> Jet_BTagPhys = {fReader, "Jet.BTagPhys"};
   TTreeReaderArray<unsigned int> Jet_TauTag = {fReader, "Jet.TauTag"};
   TTreeReaderArray<Float_t> Jet_TauWeight = {fReader, "Jet.TauWeight"};
   TTreeReaderArray<Int_t> Jet_Charge = {fReader, "Jet.Charge"};
   TTreeReaderArray<Float_t> Jet_EhadOverEem = {fReader, "Jet.EhadOverEem"};
   TTreeReaderArray<Int_t> Jet_NCharged = {fReader, "Jet.NCharged"};
   TTreeReaderArray<Int_t> Jet_NNeutrals = {fReader, "Jet.NNeutrals"};
   TTreeReaderArray<Float_t> Jet_NeutralEnergyFraction = {fReader, "Jet.NeutralEnergyFraction"};
   TTreeReaderArray<Float_t> Jet_ChargedEnergyFraction = {fReader, "Jet.ChargedEnergyFraction"};
   TTreeReaderArray<Float_t> Jet_Beta = {fReader, "Jet.Beta"};
   TTreeReaderArray<Float_t> Jet_BetaStar = {fReader, "Jet.BetaStar"};
   TTreeReaderArray<Float_t> Jet_MeanSqDeltaR = {fReader, "Jet.MeanSqDeltaR"};
   TTreeReaderArray<Float_t> Jet_PTD = {fReader, "Jet.PTD"};
   TTreeReaderArray<TLorentzVector> Jet_SoftDroppedJet = {fReader, "Jet.SoftDroppedJet"};
   TTreeReaderArray<TLorentzVector> Jet_SoftDroppedSubJet1 = {fReader, "Jet.SoftDroppedSubJet1"};
   TTreeReaderArray<TLorentzVector> Jet_SoftDroppedSubJet2 = {fReader, "Jet.SoftDroppedSubJet2"};
   TTreeReaderArray<unsigned int> Jet_TrimmedP4 = {fReader, "Jet.TrimmedP4[5]"};
   TTreeReaderArray<unsigned int> Jet_PrunedP4 = {fReader, "Jet.PrunedP4[5]"};
   TTreeReaderArray<unsigned int> Jet_SoftDroppedP4 = {fReader, "Jet.SoftDroppedP4[5]"};
   TTreeReaderArray<unsigned int> Jet_NSubJetsTrimmed = {fReader, "Jet.NSubJetsTrimmed"};
   TTreeReaderArray<Double_t> Jet_NSubJetsPruned = {fReader, "Jet.NSubJetsPruned"};
   TTreeReaderArray<Double_t> Jet_NSubJetsSoftDropped = {fReader, "Jet.NSubJetsSoftDropped"};
   TTreeReaderArray<Double_t> Jet_ExclYmerge23 = {fReader, "Jet.ExclYmerge23"};
   TTreeReaderArray<unsigned int> Jet_ExclYmerge45 = {fReader, "Jet.ExclYmerge45"};
   TTreeReaderArray<unsigned int> Jet_ExclYmerge56 = {fReader, "Jet.ExclYmerge56"};
   TTreeReaderArray<TRefArray> Jet_Constituents = {fReader, "Jet.Constituents"};
   TTreeReaderArray<TRefArray> Jet_Particles = {fReader, "Jet.Particles"};
   TTreeReaderArray<Double_t> Jet_Area = {fReader, "Jet.Area"};
   TTreeReaderValue<Int_t> Jet_size = {fReader, "Jet_size"};
   TTreeReaderArray<unsigned int> Electron_fUniqueID = {fReader, "Electron.fUniqueID"};
   TTreeReaderArray<unsigned int> Electron_fBits = {fReader, "Electron.fBits"};
   TTreeReaderArray<Float_t> Electron_PT = {fReader, "Electron.PT"};
   TTreeReaderArray<Float_t> Electron_Eta = {fReader, "Electron.Eta"};
   TTreeReaderArray<Float_t> Electron_Phi = {fReader, "Electron.Phi"};
   TTreeReaderArray<Float_t> Electron_T = {fReader, "Electron.T"};
   TTreeReaderArray<Int_t> Electron_Charge = {fReader, "Electron.Charge"};
   TTreeReaderArray<Float_t> Electron_EhadOverEem = {fReader, "Electron.EhadOverEem"};
   TTreeReaderArray<TRef> Electron_Particle = {fReader, "Electron.Particle"};
   TTreeReaderArray<Float_t> Electron_IsolationVar = {fReader, "Electron.IsolationVar"};
   TTreeReaderArray<Float_t> Electron_IsolationVarRhoCorr = {fReader, "Electron.IsolationVarRhoCorr"};
   TTreeReaderArray<Float_t> Electron_SumPtCharged = {fReader, "Electron.SumPtCharged"};
   TTreeReaderArray<Float_t> Electron_SumPtNeutral = {fReader, "Electron.SumPtNeutral"};
   TTreeReaderArray<Float_t> Electron_SumPtChargedPU = {fReader, "Electron.SumPtChargedPU"};
   TTreeReaderArray<Float_t> Electron_SumPt = {fReader, "Electron.SumPt"};
   TTreeReaderArray<Float_t> Electron_D0 = {fReader, "Electron.D0"};
   TTreeReaderArray<Float_t> Electron_DZ = {fReader, "Electron.DZ"};
   TTreeReaderArray<Float_t> Electron_ErrorD0 = {fReader, "Electron.ErrorD0"};
   TTreeReaderArray<Float_t> Electron_ErrorDZ = {fReader, "Electron.ErrorDZ"};
   TTreeReaderValue<Int_t> Electron_size = {fReader, "Electron_size"};
   TTreeReaderArray<unsigned int> Photon_fUniqueID = {fReader, "Photon.fUniqueID"};
   TTreeReaderArray<unsigned int> Photon_fBits = {fReader, "Photon.fBits"};
   TTreeReaderArray<Float_t> Photon_PT = {fReader, "Photon.PT"};
   TTreeReaderArray<Float_t> Photon_Eta = {fReader, "Photon.Eta"};
   TTreeReaderArray<Float_t> Photon_Phi = {fReader, "Photon.Phi"};
   TTreeReaderArray<Float_t> Photon_E = {fReader, "Photon.E"};
   TTreeReaderArray<Float_t> Photon_T = {fReader, "Photon.T"};
   TTreeReaderArray<Float_t> Photon_EhadOverEem = {fReader, "Photon.EhadOverEem"};
   TTreeReaderArray<TRefArray> Photon_Particles = {fReader, "Photon.Particles"};
   TTreeReaderArray<Float_t> Photon_IsolationVar = {fReader, "Photon.IsolationVar"};
   TTreeReaderArray<Float_t> Photon_IsolationVarRhoCorr = {fReader, "Photon.IsolationVarRhoCorr"};
   TTreeReaderArray<Float_t> Photon_SumPtCharged = {fReader, "Photon.SumPtCharged"};
   TTreeReaderArray<Float_t> Photon_SumPtNeutral = {fReader, "Photon.SumPtNeutral"};
   TTreeReaderArray<Float_t> Photon_SumPtChargedPU = {fReader, "Photon.SumPtChargedPU"};
   TTreeReaderArray<Float_t> Photon_SumPt = {fReader, "Photon.SumPt"};
   TTreeReaderArray<Int_t> Photon_Status = {fReader, "Photon.Status"};
   TTreeReaderValue<Int_t> Photon_size = {fReader, "Photon_size"};
   TTreeReaderArray<unsigned int> Muon_fUniqueID = {fReader, "Muon.fUniqueID"};
   TTreeReaderArray<unsigned int> Muon_fBits = {fReader, "Muon.fBits"};
   TTreeReaderArray<Float_t> Muon_PT = {fReader, "Muon.PT"};
   TTreeReaderArray<Float_t> Muon_Eta = {fReader, "Muon.Eta"};
   TTreeReaderArray<Float_t> Muon_Phi = {fReader, "Muon.Phi"};
   TTreeReaderArray<Float_t> Muon_T = {fReader, "Muon.T"};
   TTreeReaderArray<Int_t> Muon_Charge = {fReader, "Muon.Charge"};
   TTreeReaderArray<TRef> Muon_Particle = {fReader, "Muon.Particle"};
   TTreeReaderArray<Float_t> Muon_IsolationVar = {fReader, "Muon.IsolationVar"};
   TTreeReaderArray<Float_t> Muon_IsolationVarRhoCorr = {fReader, "Muon.IsolationVarRhoCorr"};
   TTreeReaderArray<Float_t> Muon_SumPtCharged = {fReader, "Muon.SumPtCharged"};
   TTreeReaderArray<Float_t> Muon_SumPtNeutral = {fReader, "Muon.SumPtNeutral"};
   TTreeReaderArray<Float_t> Muon_SumPtChargedPU = {fReader, "Muon.SumPtChargedPU"};
   TTreeReaderArray<Float_t> Muon_SumPt = {fReader, "Muon.SumPt"};
   TTreeReaderArray<Float_t> Muon_D0 = {fReader, "Muon.D0"};
   TTreeReaderArray<Float_t> Muon_DZ = {fReader, "Muon.DZ"};
   TTreeReaderArray<Float_t> Muon_ErrorD0 = {fReader, "Muon.ErrorD0"};
   TTreeReaderArray<Float_t> Muon_ErrorDZ = {fReader, "Muon.ErrorDZ"};
   TTreeReaderValue<Int_t> Muon_size = {fReader, "Muon_size"};
   TTreeReaderArray<unsigned int> FatJet_fUniqueID = {fReader, "FatJet.fUniqueID"};
   TTreeReaderArray<unsigned int> FatJet_fBits = {fReader, "FatJet.fBits"};
   TTreeReaderArray<Float_t> FatJet_PT = {fReader, "FatJet.PT"};
   TTreeReaderArray<Float_t> FatJet_Eta = {fReader, "FatJet.Eta"};
   TTreeReaderArray<Float_t> FatJet_Phi = {fReader, "FatJet.Phi"};
   TTreeReaderArray<Float_t> FatJet_T = {fReader, "FatJet.T"};
   TTreeReaderArray<Float_t> FatJet_Mass = {fReader, "FatJet.Mass"};
   TTreeReaderArray<Float_t> FatJet_DeltaEta = {fReader, "FatJet.DeltaEta"};
   TTreeReaderArray<Float_t> FatJet_DeltaPhi = {fReader, "FatJet.DeltaPhi"};
   TTreeReaderArray<unsigned int> FatJet_Flavor = {fReader, "FatJet.Flavor"};
   TTreeReaderArray<unsigned int> FatJet_FlavorAlgo = {fReader, "FatJet.FlavorAlgo"};
   TTreeReaderArray<unsigned int> FatJet_FlavorPhys = {fReader, "FatJet.FlavorPhys"};
   TTreeReaderArray<unsigned int> FatJet_BTag = {fReader, "FatJet.BTag"};
   TTreeReaderArray<unsigned int> FatJet_BTagAlgo = {fReader, "FatJet.BTagAlgo"};
   TTreeReaderArray<unsigned int> FatJet_BTagPhys = {fReader, "FatJet.BTagPhys"};
   TTreeReaderArray<unsigned int> FatJet_TauTag = {fReader, "FatJet.TauTag"};
   TTreeReaderArray<Float_t> FatJet_TauWeight = {fReader, "FatJet.TauWeight"};
   TTreeReaderArray<Int_t> FatJet_Charge = {fReader, "FatJet.Charge"};
   TTreeReaderArray<Float_t> FatJet_EhadOverEem = {fReader, "FatJet.EhadOverEem"};
   TTreeReaderArray<Int_t> FatJet_NCharged = {fReader, "FatJet.NCharged"};
   TTreeReaderArray<Int_t> FatJet_NNeutrals = {fReader, "FatJet.NNeutrals"};
   TTreeReaderArray<Float_t> FatJet_NeutralEnergyFraction = {fReader, "FatJet.NeutralEnergyFraction"};
   TTreeReaderArray<Float_t> FatJet_ChargedEnergyFraction = {fReader, "FatJet.ChargedEnergyFraction"};
   TTreeReaderArray<Float_t> FatJet_Beta = {fReader, "FatJet.Beta"};
   TTreeReaderArray<Float_t> FatJet_BetaStar = {fReader, "FatJet.BetaStar"};
   TTreeReaderArray<Float_t> FatJet_MeanSqDeltaR = {fReader, "FatJet.MeanSqDeltaR"};
   TTreeReaderArray<Float_t> FatJet_PTD = {fReader, "FatJet.PTD"};
   TTreeReaderArray<TLorentzVector> FatJet_SoftDroppedJet = {fReader, "FatJet.SoftDroppedJet"};
   TTreeReaderArray<TLorentzVector> FatJet_SoftDroppedSubJet1 = {fReader, "FatJet.SoftDroppedSubJet1"};
   TTreeReaderArray<TLorentzVector> FatJet_SoftDroppedSubJet2 = {fReader, "FatJet.SoftDroppedSubJet2"};
   TTreeReaderArray<unsigned int> FatJet_TrimmedP4 = {fReader, "FatJet.TrimmedP4[5]"};
   TTreeReaderArray<unsigned int> FatJet_PrunedP4 = {fReader, "FatJet.PrunedP4[5]"};
   TTreeReaderArray<unsigned int> FatJet_SoftDroppedP4 = {fReader, "FatJet.SoftDroppedP4[5]"};
   TTreeReaderArray<unsigned int> FatJet_NSubJetsTrimmed = {fReader, "FatJet.NSubJetsTrimmed"};
   TTreeReaderArray<Double_t> FatJet_NSubJetsPruned = {fReader, "FatJet.NSubJetsPruned"};
   TTreeReaderArray<Double_t> FatJet_NSubJetsSoftDropped = {fReader, "FatJet.NSubJetsSoftDropped"};
   TTreeReaderArray<Double_t> FatJet_ExclYmerge23 = {fReader, "FatJet.ExclYmerge23"};
   TTreeReaderArray<unsigned int> FatJet_ExclYmerge45 = {fReader, "FatJet.ExclYmerge45"};
   TTreeReaderArray<unsigned int> FatJet_ExclYmerge56 = {fReader, "FatJet.ExclYmerge56"};
   TTreeReaderArray<unsigned int> FatJet_Constituents = {fReader, "FatJet.Constituents"};
   TTreeReaderArray<unsigned int> FatJet_Particles = {fReader, "FatJet.Particles"};
   TTreeReaderArray<Double_t> FatJet_Area = {fReader, "FatJet.Area"};
   TTreeReaderValue<Int_t> FatJet_size = {fReader, "FatJet_size"};
   TTreeReaderArray<unsigned int> MissingET_fUniqueID = {fReader, "MissingET.fUniqueID"};
   TTreeReaderArray<unsigned int> MissingET_fBits = {fReader, "MissingET.fBits"};
   TTreeReaderArray<Float_t> MissingET_MET = {fReader, "MissingET.MET"};
   TTreeReaderArray<Float_t> MissingET_Eta = {fReader, "MissingET.Eta"};
   TTreeReaderArray<Float_t> MissingET_Phi = {fReader, "MissingET.Phi"};
   TTreeReaderValue<Int_t> MissingET_size = {fReader, "MissingET_size"};
   TTreeReaderArray<unsigned int> ScalarHT_fUniqueID = {fReader, "ScalarHT.fUniqueID"};
   TTreeReaderArray<unsigned int> ScalarHT_fBits = {fReader, "ScalarHT.fBits"};
   TTreeReaderArray<Float_t> ScalarHT_HT = {fReader, "ScalarHT.HT"};
   TTreeReaderValue<Int_t> ScalarHT_size = {fReader, "ScalarHT_size"};
   /* TTreeReaderValue<Float_t> MyNewBranchName = {fReader, "MyNewBranchName"}; */
   TTreeReaderArray<float> myTowerET = {fReader, "myTowerET"};
   TTreeReaderArray<float> myTowerEta = {fReader, "myTowerEta"};
   TTreeReaderArray<float> myTowerPhi = {fReader, "myTowerPhi"};


   TestTreeModifierSelector(TTree * /*tree*/ =0) { }
   virtual ~TestTreeModifierSelector() { }
   virtual Int_t   Version() const { return 2; }
   virtual void    Begin(TTree *tree);
   virtual void    SlaveBegin(TTree *tree);
   virtual void    Init(TTree *tree);
   virtual Bool_t  Notify();
   virtual Bool_t  Process(Long64_t entry);
   virtual Int_t   GetEntry(Long64_t entry, Int_t getall = 0) { return fChain ? fChain->GetTree()->GetEntry(entry, getall) : 0; }
   virtual void    SetOption(const char *option) { fOption = option; }
   virtual void    SetObject(TObject *obj) { fObject = obj; }
   virtual void    SetInputList(TList *input) { fInput = input; }
   virtual TList  *GetOutputList() const { return fOutput; }
   virtual void    SlaveTerminate();
   virtual void    Terminate();

   ClassDef(TestTreeModifierSelector,0);
   
   Float_t total_constituents = 0;
   Float_t particles_in_jets = 0;
   Float_t tracks_in_jets = 0;
   Float_t towers_in_jets = 0;

};

#endif

#ifdef TestTreeModifierSelector_cxx
void TestTreeModifierSelector::Init(TTree *tree)
{
   // The Init() function is called when the selector needs to initialize
   // a new tree or chain. Typically here the reader is initialized.
   // It is normally not necessary to make changes to the generated
   // code, but the routine can be extended by the user if needed.
   // Init() will be called many times when running on PROOF
   // (once per file to be processed).

   fReader.SetTree(tree);
}

Bool_t TestTreeModifierSelector::Notify()
{
   // The Notify() function is called when a new file is opened. This
   // can be either for a new TTree in a TChain or when when a new TTree
   // is started when using PROOF. It is normally not necessary to make changes
   // to the generated code, but the routine can be extended by the
   // user if needed. The return value is currently not used.

   return kTRUE;
}


#endif // #ifdef TestTreeModifierSelector_cxx
