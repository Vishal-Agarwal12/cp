int check(int mid) {
    last_painter_time_left = 0;
    num_of_painter_spawned = 0;
    
    for(int i=0;i<n;i++) {
        if(last_painter_time_left >= arr[i]) {
            last_painter_time_left -= arr[i];
        }
        else {
            num_of_painter_spawned++;
            if(num_of_painter_spawned > k) {
                return 0;
            }
            
            last_painter_time_left = mid;
            if(last_painter_time_left >= arr[i]) {
                last_painter_time_left -= arr[i];
            }
            else {
                return 0; // even a single wall cannot be painted by painter
            }
        }
    }
    
    return 1;
}
