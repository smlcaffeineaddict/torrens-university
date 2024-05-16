/*=============== SHOW MODAL ===============*/
const showModal = (openButton, modalContent) =>{
    const openBtn = document.getElementById(openButton),
    modalContainer = document.getElementById(modalContent)
    
    if(openBtn && modalContainer){
        openBtn.addEventListener('click', ()=>{
            modalContainer.classList.add('show-modal')
        })
    }
}
showModal('open-modal-1','modal-container-1')
showModal('open-modal-2','modal-container-2')
showModal('open-modal-3','modal-container-3')
showModal('open-modal-4','modal-container-4')
showModal('open-modal-5','modal-container-5')
showModal('open-modal-6','modal-container-6')
showModal('open-modal-7','modal-container-7')
showModal('open-modal-8','modal-container-8')
showModal('open-modal-9','modal-container-9')
showModal('open-modal-10','modal-container-10')
showModal('open-modal-11','modal-container-11')
showModal('open-modal-12','modal-container-12')
showModal('open-modal-13','modal-container-13')
showModal('open-modal-14','modal-container-14')
showModal('open-modal-15','modal-container-15')
showModal('open-modal-16','modal-container-16')

/*=============== CLOSE MODAL ===============*/
const closeBtn = document.querySelectorAll('.close-modal')

function closeModal(modalContainerId) {
    const modalContainer = document.getElementById(modalContainerId)
    modalContainer.classList.remove('show-modal')
}

closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-1')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-2')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-3')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-4')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-5')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-6')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-7')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-8')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-9')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-10')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-11')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-12')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-13')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-14')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-15')))
closeBtn.forEach(c => c.addEventListener('click', () => closeModal('modal-container-16')))