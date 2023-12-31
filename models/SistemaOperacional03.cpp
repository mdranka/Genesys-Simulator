/*
 * This C++ program was automatically generated by Genesys 220517 (gowndictator)
 * For your own safety, please review this file before compiling and running it.
 */

#include "kernel/simulator/Simulator.h"
#include "plugins/components/Assign.h"
#include "plugins/components/Create.h"
#include "plugins/components/Decide.h"
#include "plugins/components/Delay.h"
#include "plugins/components/Dispose.h"
#include "plugins/components/Enter.h"
#include "plugins/components/Release.h"
#include "plugins/components/Route.h"
#include "plugins/components/Seize.h"
#include "plugins/data/Attribute.h"
#include "plugins/data/EntityType.h"
#include "plugins/data/Queue.h"
#include "plugins/data/Resource.h"
#include "plugins/data/Set.h"
#include "plugins/data/Station.h"

int main(int argc, char** argv) {
	// instantiate simulator
	Simulator* genesys = new Simulator();
	genesys->getTracer()->setTraceLevel(TraceManager::Level::L9_mostDetailed);
	PluginManager* plugins = genesys->getPlugins();
	
	// create model
	Model* model = genesys->getModels()->newModel();
	// model->load("model.gen")
	
	// initialize model parts
	Create* Create_1 = plugins->newInstance<Create>(model, "Create_1");
	EntityType* processo = plugins->newInstance<EntityType>(model, "processo");
	Assign* Assign_1 = plugins->newInstance<Assign>(model, "Assign_1");
	Attribute* memoriaOcupada = plugins->newInstance<Attribute>(model, "memoriaOcupada");
	Attribute* tempoExecucao = plugins->newInstance<Attribute>(model, "tempoExecucao");
	Attribute* processoSO = plugins->newInstance<Attribute>(model, "processoSO");
	Resource* memoria = plugins->newInstance<Resource>(model, "memoria");
	Queue* Fila_Alocacao_Memoria = plugins->newInstance<Queue>(model, "Fila_Alocacao_Memoria");
	Seize* Seize_1 = plugins->newInstance<Seize>(model, "Seize_1");
	Decide* Decide_1 = plugins->newInstance<Decide>(model, "Decide_1");
	Assign* Assign_2 = plugins->newInstance<Assign>(model, "Assign_2");
	Attribute* nucleoExecucao = plugins->newInstance<Attribute>(model, "nucleoExecucao");
	Assign* Assign_3 = plugins->newInstance<Assign>(model, "Assign_3");
	Assign* Assign_4 = plugins->newInstance<Assign>(model, "Assign_4");
	Assign* Assign_5 = plugins->newInstance<Assign>(model, "Assign_5");
	Station* Estacao_de_Execucao = plugins->newInstance<Station>(model, "Estacao_de_Execucao");
	Route* Route_1 = plugins->newInstance<Route>(model, "Route_1");
	Enter* Enter_1 = plugins->newInstance<Enter>(model, "Enter_1");
	Set* Set_Nucleos = plugins->newInstance<Set>(model, "Set_Nucleos");
	Resource* nucleo0 = plugins->newInstance<Resource>(model, "nucleo0");
	Resource* nucleo1 = plugins->newInstance<Resource>(model, "nucleo1");
	Resource* nucleo2 = plugins->newInstance<Resource>(model, "nucleo2");
	Resource* nucleo3 = plugins->newInstance<Resource>(model, "nucleo3");
	Set* Set_Filas = plugins->newInstance<Set>(model, "Set_Filas");
	Queue* filaNucleo0 = plugins->newInstance<Queue>(model, "filaNucleo0");
	Queue* filaNucleo1 = plugins->newInstance<Queue>(model, "filaNucleo1");
	Queue* filaNucleo2 = plugins->newInstance<Queue>(model, "filaNucleo2");
	Queue* filaNucleo3 = plugins->newInstance<Queue>(model, "filaNucleo3");
	Seize* Seize_2 = plugins->newInstance<Seize>(model, "Seize_2");
	Decide* Decide_2 = plugins->newInstance<Decide>(model, "Decide_2");
	Assign* Assign_6 = plugins->newInstance<Assign>(model, "Assign_6");
	Attribute* fatiaTempo = plugins->newInstance<Attribute>(model, "fatiaTempo");
	Assign* Assign_7 = plugins->newInstance<Assign>(model, "Assign_7");
	Delay* Delay_1 = plugins->newInstance<Delay>(model, "Delay_1");
	Release* Release_1 = plugins->newInstance<Release>(model, "Release_1");
	Decide* Decide_3 = plugins->newInstance<Decide>(model, "Decide_3");
	Route* Route_2 = plugins->newInstance<Route>(model, "Route_2");
	Station* Estacao_de_liberacao_de_memoria = plugins->newInstance<Station>(model, "Estacao_de_liberacao_de_memoria");
	Route* Route_3 = plugins->newInstance<Route>(model, "Route_3");
	Enter* Enter_2 = plugins->newInstance<Enter>(model, "Enter_2");
	Release* Release_2 = plugins->newInstance<Release>(model, "Release_2");
	Dispose* Dispose_1 = plugins->newInstance<Dispose>(model, "Dispose_1");
	
	// connect model components
	Create_1->getConnections()->insert(Assign_1, 0);
	Assign_1->getConnections()->insert(Seize_1, 0);
	Seize_1->getConnections()->insert(Decide_1, 0);
	Decide_1->getConnections()->insert(Assign_2, 0);
	Decide_1->getConnections()->insert(Assign_3, 0);
	Decide_1->getConnections()->insert(Assign_4, 0);
	Decide_1->getConnections()->insert(Assign_5, 0);
	Assign_2->getConnections()->insert(Route_1, 0);
	Assign_3->getConnections()->insert(Route_1, 0);
	Assign_4->getConnections()->insert(Route_1, 0);
	Assign_5->getConnections()->insert(Route_1, 0);
	Enter_1->getConnections()->insert(Seize_2, 0);
	Seize_2->getConnections()->insert(Decide_2, 0);
	Decide_2->getConnections()->insert(Assign_6, 0);
	Decide_2->getConnections()->insert(Assign_7, 0);
	Assign_6->getConnections()->insert(Delay_1, 0);
	Assign_7->getConnections()->insert(Delay_1, 0);
	Delay_1->getConnections()->insert(Release_1, 0);
	Release_1->getConnections()->insert(Decide_3, 0);
	Decide_3->getConnections()->insert(Route_2, 0);
	Decide_3->getConnections()->insert(Route_3, 0);
	Enter_2->getConnections()->insert(Release_2, 0);
	Release_2->getConnections()->insert(Dispose_1, 0);
	
	// set simulation parameters
	ModelSimulation* sim = model->getSimulation();
	sim->setNumberOfReplications(1);
	sim->setReplicationLengthTimeUnit(Util::TimeUnit::second);
	sim->setReplicationLength(2.000000);
	sim->setReplicationReportBaseTimeUnit(Util::TimeUnit::milisecond);
	
	// run the simulation
	sim->start();
	
	// free memory
	delete genesys;
	
	return 0;
}
