/*==================== SEARCH BAR ====================*/
const container = document.querySelector(".nav__right");
const searchIcons = document.querySelectorAll(".nav__search i");

searchIcons.forEach(searchIcon => {
  searchIcon.addEventListener("click", () => {
    container.classList.toggle("change");
  });
})