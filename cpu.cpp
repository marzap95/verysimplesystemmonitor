class Cpu {
private:
  int core;
public:
  Cpu(int cored){
    core = cored;
  }

  int get_used(){
    ifstream inputfile;
    string line;
    int x;
    int work_jiffies_0 = 0;
    int work_jiffies_1 = 0;
    int total_jiffies_0 = 0;
    int total_jiffies_1 = 0;
    inputfile.open("/proc/stat");
    getline(inputfile, line);
    for(int i = 0; i < core; i++){
      getline(inputfile, line);
    }
    for(int i = 0; i < 11; i++){
      if(i == 0){
        inputfile >> line;
        continue;
      }
      inputfile >> x;
      if(i < 4) work_jiffies_0+=x;
      total_jiffies_0+=x;
    }
    inputfile.close();
    inputfile.open("/proc/stat");
    getline(inputfile, line);
    for(int i = 0; i < core; i++){
      getline(inputfile, line);
    }
    for(int i = 0; i < 11; i++){
      if(i == 0) continue;
      inputfile >> x;
      if(i < 4) work_jiffies_1+=x;
      total_jiffies_1+=x;
    }
    inputfile.close();
    return (int)(
      ((float)(work_jiffies_1 - work_jiffies_0) /
      (float)(total_jiffies_1 - total_jiffies_0))
      * 100
    );
  }
};
