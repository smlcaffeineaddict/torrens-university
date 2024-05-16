let currentSong = 0;
let isPlaying = false;
let audioPlayer1 = new Audio();
let audioPlayer2 = new Audio();

// Function to update the UI
function updateUI() {
  const trackArt = document.querySelectorAll(".track__art");
  const trackName = document.querySelectorAll(".track__name");
  const trackArtist = document.querySelectorAll(".track__artist");
  const playPauseIcons = document.querySelectorAll(".playpause__track i");
  const currentTimes = document.querySelectorAll(".current__time");
  const totalDurations = document.querySelectorAll(".total__duration");
  const seekSliders = document.querySelectorAll(".seek_slider");
  const volumeSliders = document.querySelectorAll(".volume_slider");

  trackArt.forEach(art => art.style.backgroundImage = `url('${songs[currentSong].trackArt}')`);
  trackName.forEach(name => name.textContent = songs[currentSong].name);
  trackArtist.forEach(artist => artist.textContent = songs[currentSong].artist);
  playPauseIcons.forEach(icon => icon.classList.remove("ri-play-circle-fill", "ri-pause-circle-fill"));
  playPauseIcons.forEach(icon => icon.classList.add(isPlaying ? "ri-pause-circle-fill" : "ri-play-circle-fill"));

  // Update track times
  const updateTimes = () => {
    const currentTime = isPlaying ? formatTime(audioPlayer1.currentTime) : "0:00";
    const duration = formatTime(audioPlayer1.duration);
    currentTimes.forEach(time => time.textContent = currentTime);
    totalDurations.forEach(totalDuration => totalDuration.textContent = duration);
    seekSliders.forEach(slider => slider.value = (audioPlayer1.currentTime / audioPlayer1.duration) * 100 || 0);
  };
  audioPlayer1.addEventListener("loadedmetadata", () => {
    updateTimes();
    seekSliders.forEach(slider => slider.value = 0); // Reset seek slider to 0
    volumeSliders.forEach(slider => slider.value = 25); // Set default volume to 25%
  });

  audioPlayer1.addEventListener("timeupdate", updateTimes);
  audioPlayer2.addEventListener("timeupdate", updateTimes);

  // Update track list
  const trackList = document.querySelector(".track__list");
  trackList.innerHTML = "";
  songs.forEach((song, index) => {
    const listItem = document.createElement("li");
    listItem.classList.add("track__item");
    listItem.addEventListener("click", () => {
      currentSong = index;
      updateUI();
      playpauseTrack();
    });

    const trackNumberElement = document.createElement("span");
    trackNumberElement.classList.add("track__number");
    
    if (index === currentSong) {
      const playPauseButton = document.createElement("i");
      playPauseButton.classList.add("track__number","playpause", "ri-play-large-fill"); // Default to play icon
    
      if (isPlaying) {
        playPauseButton.classList.replace("ri-play-large-fill", "ri-pause-large-fill"); // Change to pause icon
      }
      listItem.appendChild(playPauseButton);
    } else {
      trackNumberElement.textContent = index + 1;
      listItem.appendChild(trackNumberElement);
    }
    
    const outerDiv = document.createElement("div");
    outerDiv.classList.add("track__info");
    
    const trackName = document.createElement("span");
    trackName.classList.add("track__name");
    trackName.textContent = `${song.name}`;
    
    const trackArtist = document.createElement("span");
    trackArtist.classList.add("track__artist");
    trackArtist.textContent = `${song.artist}`;
    
    outerDiv.appendChild(trackName);
    outerDiv.appendChild(trackArtist);
    
    listItem.appendChild(outerDiv);
    const trackDuration = document.createElement("span");
    trackDuration.classList.add("track__duration");

    if (index === currentSong) {
      trackDuration.textContent = isPlaying ? formatTime(audioPlayer2.currentTime) : song.duration;
    } 
    else {
      trackDuration.textContent = song.duration;
    }
    listItem.appendChild(trackDuration);

    trackList.appendChild(listItem);

  });

  // Sync sliders
  seekSliders.forEach(slider => {
    slider.value = (audioPlayer1.currentTime / audioPlayer1.duration) * 100 || 0;
    slider.addEventListener("input", () => {
      const seekTime = slider.value * audioPlayer1.duration / 100;
      audioPlayer1.currentTime = seekTime;
      audioPlayer2.currentTime = seekTime;
    });
  });

  volumeSliders.forEach(slider => {
    slider.value = audioPlayer1.volume * 100;
    slider.addEventListener("input", () => {
      const newVolume = slider.value / 100;
      audioPlayer1.volume = newVolume;
      audioPlayer2.volume = newVolume;
    });
  });
}

// Function to play or pause the tracks
function playpauseTrack() {
  if (isPlaying) {
    audioPlayer1.pause();
    audioPlayer2.pause();
  } else {
    audioPlayer1.src = songs[currentSong].path;
    audioPlayer2.src = songs[currentSong].path;
    audioPlayer1.play();
    audioPlayer2.play();
  }
  isPlaying = !isPlaying;
  updateUI();
}

// Function to go to the next track
function nextTrack() {
  currentSong = (currentSong + 1) % songs.length;
  updateUI();
  playpauseTrack();
}

// Function to go to the previous track
function prevTrack() {
  currentSong = (currentSong - 1 + songs.length) % songs.length;
  updateUI();
  playpauseTrack();
}

// Helper function to format time
function formatTime(time) {
  const minutes = Math.floor(time / 60);
  const seconds = Math.floor(time % 60);
  return `${minutes}:${seconds.toString().padStart(2, '0')}`;
}

// Initialize the UI
updateUI();