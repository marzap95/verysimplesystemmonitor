class Ram {
  public:
    int get_total(){
      ifstream inputfile;
      string stringa;
      int tot;
      inputfile.open("/proc/meminfo");
      inputfile >> stringa;
      inputfile >> tot;
      inputfile.close();
      return tot;
    }
    int get_used(){
      ifstream inputfile;
      string stringa;
      int libera;
      int used;
      int totale = get_total();
      inputfile.open("/proc/meminfo");
      getline(inputfile, stringa);
      getline(inputfile, stringa);
      inputfile >> stringa;
      inputfile >> libera;
      used = totale - libera;
      inputfile.close();
      return used;
    }
    int get_used_percent(){
      float percent;
      int used = get_used();
      int total = get_total();
      percent = ((float)used/(float)total) * 100;
      cout << used << " " << total << " " << percent << endl;
      return (int)percent;
    }
};
