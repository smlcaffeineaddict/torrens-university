/* ==================== ADDING COMMENTS ==================== */
const commentText = document.getElementById('comment__text');
const submitComment = document.getElementById('submit__comment');
const commentsContainer = document.getElementById('comments__container');
const usernameInput = document.getElementById('username');
const profilePictureInput = document.getElementById('profile-picture');
const saveUserInfo = document.getElementById('save__user-info');

let currentUsername = localStorage.getItem('username') || 'Anonymous';
let currentProfilePicture = localStorage.getItem('profilePicture') || null;
usernameInput.value = currentUsername;

const resetComments = document.getElementById('reset-comments');

// Regular expressions for @mentions and hashtags
const mentionRegex = /@(\w+)/g;
const hashtagRegex = /#(\w+)/g;

// Function to parse and replace @mentions and hashtags
function parseCommentText(text) {
  return text
    .replace(mentionRegex, '<a href="/user/$1">@$1</a>')
    .replace(hashtagRegex, '<a href="/hashtag/$1">#$1</a>');
}

// Initial comments
const initialComments = [
  {
    text: "We can't wait to unveil the FULL lineup for the Elektrik Eel Festival! Get ready to be AMAZED. #ElektrikEelFest #FestivalLineup ⚡️",
    author: "ElektrikEel",
    profilePicture: "assets/img/comment-img/elektrik-eel.png",
    date: generateCommentDate(1)
  },
  {
    text: "OMG! Just scored tickets to the Elektrik Eel Festival with my besties! Any tips for a first-time festival goer? #ElektrikEelFest #FestivalNewbie",
    author: "Emma ✨",
    profilePicture: "assets/img/comment-img/emma.png",
    date: generateCommentDate(1, 5)
  },
  {
    text: "Scrolling through the #ElektrikEelFest lineup. Can't wait to see Surgeon live!",
    author: "LeanDean",
    profilePicture: "assets/img/comment-img/dean.png",
    date: generateCommentDate(1, 5)
  },
  {
    text: "Replying to @LauraMae: We love your sense of humour! Keep the Elektrik Eel memes coming! #ElektricEelFest #FestivalFun ⚡",
    author: "ElektrikEel",
    profilePicture: "assets/img/comment-img/elektrik-eel.png",
    date: generateCommentDate(1, 5)
  }
];

function generateCommentDate(offsetDays = 0, offsetHours = 0) {
    const now = new Date();
    now.setDate(now.getDate() - offsetDays);
    now.setHours(now.getHours() - offsetHours);
    return now.toISOString().split('T')[0];
  }

// Function to load comments from the server
function loadCommentsFromServer() {
  const storedComments = localStorage.getItem('comments');
  const comments = storedComments ? JSON.parse(storedComments) : initialComments;
  commentsContainer.innerHTML = '';
  comments.forEach(comment => renderComment(comment));
}

// Function to render a comment
function renderComment(commentData) {
  const comment = document.createElement('div');
  comment.classList.add('comment');

  const profilePictureCol = document.createElement('div');
  profilePictureCol.classList.add('comment-profile-picture-col');

  const profilePicture = document.createElement('img');
  profilePicture.classList.add('comment-profile-picture');
  profilePicture.src = commentData.profilePicture || '/default-profile-picture.png';
  profilePicture.alt = `${commentData.author}'s profile picture`;

  profilePictureCol.appendChild(profilePicture);

  const contentCol = document.createElement('div');
  contentCol.classList.add('comment-content-col');

  const headerRow = document.createElement('div');
  headerRow.classList.add('comment-header-row');

  const author = document.createElement('span');
  author.classList.add('comment-author');
  author.textContent = `${commentData.author}`;

  const date = document.createElement('span');
  date.classList.add('comment-date');
  date.textContent = new Date(commentData.date).toLocaleDateString(); // Only show the date

  headerRow.appendChild(author);
  headerRow.appendChild(date);

  const text = document.createElement('div');
  text.classList.add('comment__text');
  text.innerHTML = parseCommentText(commentData.text);

  contentCol.appendChild(headerRow);
  contentCol.appendChild(text);

  comment.appendChild(profilePictureCol);
  comment.appendChild(contentCol);

  commentsContainer.appendChild(comment);
}

// Load comments from the server on page load
loadCommentsFromServer();

// Event listener for submitting a new comment
submitComment.addEventListener('click', () => {
  const commentText = document.getElementById('comment__text').value;
  if (commentText.trim()) {
    const newComment = {
      text: commentText,
      author: currentUsername,
      profilePicture: currentProfilePicture,
      date: new Date().toISOString()
    };

    // Render the new comment locally
    renderComment(newComment);

    // Get existing comments from localStorage or use initialComments
    const storedComments = localStorage.getItem('comments');
    const comments = storedComments ? JSON.parse(storedComments) : initialComments;

    // Add the new comment to the comments array
    comments.push(newComment);

    // Save the updated comments to localStorage
    localStorage.setItem('comments', JSON.stringify(comments));

    // Clear the comment text input
    document.getElementById('comment__text').value = '';
  }
});

// Function to save user information to localStorage
function saveUserInfoToLocalStorage(username, profilePicture) {
  localStorage.setItem('username', username);
  localStorage.setItem('profilePicture', profilePicture);
}

// Event listener for saving user information
saveUserInfo.addEventListener('click', () => {
  const newUsername = usernameInput.value.trim();
  if (newUsername) {
    currentUsername = newUsername;

    const file = profilePictureInput.files[0];
    if (file) {
      const reader = new FileReader();
      reader.onload = () => {
        currentProfilePicture = reader.result;
        saveUserInfoToLocalStorage(currentUsername, currentProfilePicture);
      };
      reader.readAsDataURL(file);
    } else {
      currentProfilePicture = null;
      saveUserInfoToLocalStorage(currentUsername, currentProfilePicture);
    }
  }
});

// Event listener for resetting comments
resetComments.addEventListener('click', () => {
    if (confirm('Are you sure you want to reset all comments?')) {
      localStorage.removeItem('comments');
      commentsContainer.innerHTML = '';
    }
  });